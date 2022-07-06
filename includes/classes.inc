<?php

module_load_include('inc', 'lib4ri_datacite_alert', 'includes/define');
module_load_include('inc', 'lib4ri_datacite_alert', 'includes/queries');
module_load_include('inc', 'lib4ri_pub_db', 'utils/data_servant_classes');
module_load_include('inc', 'lib4ri_pub_db', 'includes/functions');


class DataCiteRetrieval{
    protected $serv;
    protected $data;
    protected $start_date;
    protected $end_date;
    protected $to_add = [];
    protected $discarded = [];
    protected $doraPid = NULL;
    protected $doi = NULL;
        
    /**
     * Constructor
     */
    public function __construct($filter = true) {
        if ($filter){
        $this->serv = new Lib4riDataCiteDoisServant();
        }
        else{
            $this->serv = new DataCiteDoisServant();
        }
    }
    
    public function setDefQuery(){
        $relation_types = explode(',', trim(variable_get('lib4ri_pub_db_resdata_enrich_relations', 'IsSupplementTo')));
        foreach ($relation_types as $type){
            $this->serv->pushRelationType(trim($type));
        }
        
        $relation_types_excl = explode(',', trim(variable_get('lib4ri_pub_db_resdata_enrich_excl_relations', 'IsObsoletedBy, IsPartOf')));
        foreach ($relation_types_excl as $type){
            $this->serv->pushExcludeRelationType(trim($type));
        }
        
        $publishers = lib4ri_pub_db_get_data_publishers(TRUE);
        foreach ($publishers as $publisher){
            $this->serv->pushPublisher(trim($publisher->publisher_string));
        }
        
        return $this;
    }
    
    public function setStartDate($date){
        $this->start_date = $date;
        
        return $this;
    }
    
    public function setEndDate($date){
        $this->end_date = $date;
        
        return $this;
    }
    
    public function setDateQuery(){
        $this->serv->pushQueryElement("updated", "[$this->start_date TO $this->end_date]");
        
        return $this;
    }
    
    public function fetch(){
        $this->data = $this->normalize($this->serv->serve()->getProcessedArray());
                
        return $this;
    }
    
    private function isInList($item, $identifier, $any_related = FALSE){
        $ids = lib4ri_datacite_alert_get_ids($item, $identifier, $any_related);

        if (count($ids) > 0){
            return $ids;
        }
        
        return NULL;
    }
    
    public function setDoraPid($pid){
        $this->doraPid = $pid;
        
        return $this;
    }
    
    public function doraPidReset(){
        $this->doraPid = NULL;
        
        return $this;
    }
    
    private function getDoraPid($doi){
//         if ($this->doraPid){
//             return $this->doraPid;
//         }
        
         $collections = array_map(function($val){return 'RELS_EXT_isMemberOfCollection_uri_ms:info\\:fedora/'.$val;},str_replace(':','\\:',array_map('trim',explode(',',variable_get('lib4ri_pub_db_search_collections')))));
         $cond = array();
         array_push($cond, variable_get('lib4ri_pub_db_resdata_solr_doi_field').':'.islandora_solr_lesser_escape($doi));
        
         $params['f'][0] = implode(' OR ', $cond);
         $params['f'][1] = implode(' OR ', $collections);
        
         $sq = new IslandoraSolrQueryProcessor();
        
//         // Build and execute Apache Solr query.
         $sq->buildQuery('*:*', $params);
         $sq->solrParams['facet'] = "false";
         $sq->solrParams['fl'] = 'PID';
         $sq->solrLimit = '10';
         $sq->executeQuery(FALSE, TRUE);
        
         $solr_response = [];
         foreach ($sq->islandoraSolrResult['response']['objects'] as $object) {
             array_push($solr_response, $object['solr_doc']);
         }
        
         $pids = [];
         foreach ($solr_response as $repoobj){
             array_push($pids, $repoobj['PID']);
         }
         
         if (count($pids) == 0){
             return false;
         }
         
         return implode(';', $pids);
         
    }
    
    private function norm_single($element){
        if(!isset($element)){
            return null;
        }
        
        if (!isset($element[0])){
            $out = array();
            $out[0] = $element;
            return $out;
        }

        return $element;
    }
    
    private function normalize($data){
        $out = array();
 
        $data = $this->norm_single($data);
//         if (!isset($data[0])){
//             unset($temp);
//             $temp = $data;
//             unset($data);
//             $data = array();
//             $data[0] = $temp;
//         }
        
        foreach ($data as $element){
             
            $element['item'] = $this->norm_single($element['item']);
            if (isset($element['item'])){
                foreach ($element['item'] as $item){
                    $item['relatedIdentifiers'] = $this->norm_single($item['relatedIdentifiers']['item']);
                    array_push($out, $item);
                    unset($item);
                }
            }
        }
        
        return $out;
    }
    
    public function filter(){
        foreach ($this->data as $item){
            foreach ($item['relatedIdentifiers'] as $identifier){                              
                $identifier['pid'] = $this->getDoraPid($identifier['relatedIdentifier']); //checks if related identifier is in DORA
//                $ids = $this->isInList($item, $identifier); //checks if it's already in the alert list
                $ids = $this->isInList($item, $identifier['pid'], TRUE); //checks if it's already in the alert list
                if (($identifier['pid'] !== false) && ($ids == NULL)){
                    array_push($this->to_add, array('item' => $item, 'identifier' => $identifier));
                }
                else{
                    array_push($this->discarded, array('item' => $item, 'identifier' => $identifier, 'ids' => $ids));
                }
            }
            
        }
        
        return $this;
    }
    
    public function filterSingleDoi(){
        foreach ($this->data as $item){
            foreach ($item['relatedIdentifiers'] as $identifier){
//                $ids = $this->isInList($item, $identifier); //checks if it's already in the alert list
                $ids = $this->isInList($item, $this->doraPid, TRUE); //checks if it's already in the alert list
                if((strtolower($identifier['relatedIdentifier']) == $this->doi) && ($ids == NULL)){
                    $identifier['pid'] = $this->doraPid;
                    array_push($this->to_add, array('item' => $item, 'identifier' => $identifier));
                }
                else{
                    array_push($this->discarded, array('item' => $item, 'identifier' => $identifier, 'ids' => $ids));
                }
            }
        }
        
        return $this;
    }
    
    public function filterIgnoreRelated(){
        foreach ($this->data as $item){
            $ids = $this->isInList($item, $this->doraPid, TRUE); //checks if it's already in the alert list
            if ($ids == NULL){
                array_push($this->to_add, array('item' => $item, 'identifier' => array('relationType' => 'Added manually', 'pid' => $this->doraPid)));
            }
            else{
                array_push($this->discarded, array('item' => $item, 'identifier' => array('relationType' => 'Added manually', 'pid' => $this->doraPid), 'ids' => $ids));
            }
        }
    }
    
    
    public function update(){
        
        foreach ($this->to_add as $item){
                    lib4ri_datacite_alert_insert_data($item['item'], $item['identifier']);
        }
        
        return $this;
    }
    
    public function setDoi($doi){
        $this->doi = $doi;
        $this->serv->setDoi($doi);
        
        return $this;
    }
    
    public function getData(){
        return $this->data;
    }
    
    public function getToAdd(){
        return $this->to_add;
    }

    public function getDiscarded(){
        return $this->discarded;
    }
    
    public function setPackageDoi($doi){
        $this->serv->pushQueryElement("doi", strtoupper($doi));
        
        return $this;
    }
    
}