<?php

module_load_include('inc', 'lib4ri_datacite_alert', 'includes/define');
module_load_include('inc', 'lib4ri_datacite_alert', 'includes/queries');
module_load_include('inc', 'lib4ri_pub_db', 'utils/data_servant_classes');
module_load_include('inc', 'lib4ri_pub_db', 'includes/functions');


class DataCiteRetrieval{
    protected $serv;
    protected $data;
    
        
    /**
     * Constructor
     */
    public function __construct() {
        $this->serv = new Lib4riDataCiteDoisServant();
        $relation_types = explode(',', trim(variable_get('lib4ri_pub_db_resdata_enrich_relations', 'IsSupplementTo')));
        foreach ($relation_types as $type){
            $this->serv->pushRelationType(trim($type));
        }
        
        $relation_types_excl = explode(',', trim(variable_get('lib4ri_pub_db_resdata_enrich_excl_relations', 'IsObsoletedBy, IsPartOf')));
        foreach ($relation_types_excl as $type){
            $this->serv->pushExcludeRelationType(trim($type));
        }
        
        //        $publishers = explode("\n", trim(variable_get('lib4ri_pub_db_resdata_enrich_publishers')));
        $publishers = lib4ri_pub_db_get_data_publishers(TRUE);
        foreach ($publishers as $publisher){
            $this->serv->pushPublisher(trim($publisher->publisher_string));
        }
        
        $this->serv->pushQueryElement("updated", '[2022-03-09T00:00:00Z TO now]'); //TODO
    }
    
    public function fetch(){
        $this->data = $this->normalize($this->serv->serve()->getProcessedArray());
        
        $this->to_insert = array();
        foreach ($this->data as $item){
            foreach ($item['relatedIdentifiers'] as $identifier){
                lib4ri_datacite_alert_insert_data($item, $identifier);
            }
            
        }
        
        return $this;
    }
        
    private function getDoraPid($doi){
        
        //TODO
//         $collections = array_map(function($val){return 'RELS_EXT_isMemberOfCollection_uri_ms:info\\:fedora/'.$val;},str_replace(':','\\:',array_map('trim',explode(',',variable_get('publication_DB_search_collections')))));
        
//         array_push($cond, variable_get('protein_db_solr_doi_field').':'.islandora_solr_lesser_escape($doi));
        
//         $params['f'][0] = implode(' OR ', $cond);
//         $params['f'][1] = implode(' OR ', $collections);
        
//         $sq = new IslandoraSolrQueryProcessor();
        
//         // Build and execute Apache Solr query.
//         $sq->buildQuery('*:*', $params);
//         $sq->solrParams['facet'] = "false";
//         $sq->solrParams['fl'] = 'PID, '.variable_get('protein_db_solr_beamline_field').', '. variable_get('protein_db_solr_facility_field');
//         $sq->solrLimit = '10';
//         $sq->executeQuery(FALSE, TRUE);
        
//         $solr_response = [];
//         foreach ($sq->islandoraSolrResult['response']['objects'] as $object) {
//             array_push($solr_response, $object['solr_doc']);
//         }
        
//         return $solr_response;
        
    }
    
    private function norm_single($element){
        
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
            foreach ($element['item'] as $item){
                $item['relatedIdentifiers'] = $this->norm_single($item['relatedIdentifiers']['item']);
                array_push($out, $item);
                unset($item);
            }
        }
        
        return $out;
    }
    
    public function update(){
        $this->fetch();
        
        return $this;
    }
}