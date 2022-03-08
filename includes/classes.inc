<?php

module_load_include('inc', 'lib4ri_datacite_alert', 'includes/define');
module_load_include('php', 'publication_DB', 'lib/MetaDataServants');
module_load_include('inc', 'publication_DB', 'includes/functions');


class DataCiteRetrieval{
    protected $serv;
    protected $data;
    
        
    /**
     * Constructor
     */
    public function __construct() {
        $this->serv = new DataCiteDoisServant();
        $relation_types = explode(',', trim(variable_get('lib4ri_pub_db_resdata_enrich_relations', 'IsSupplementTo')));
        foreach ($relation_types as $type){
            $res_data_fetcher->pushRelationType(trim($type));
        }
        
        $relation_types_excl = explode(',', trim(variable_get('lib4ri_pub_db_resdata_enrich_excl_relations', 'IsObsoletedBy, IsPartOf')));
        foreach ($relation_types as $type){
            $res_data_fetcher->pushRelationType(trim($type));
        }
        
        //        $publishers = explode("\n", trim(variable_get('lib4ri_pub_db_resdata_enrich_publishers')));
        $publishers = lib4ri_pub_db_get_data_publishers(TRUE);
        foreach ($publishers as $publisher){
            $res_data_fetcher->pushPublisher(trim($publisher->publisher_string));
        }
    }
    
    public function fetch(){
        $this->serv->pushQueryElement("updated", '[2022-03-08T00:00:00Z TO now]');
        $this->data = $serv->getProcessedArray();
        
        return $this;
    }
    
    public function insert(){
        
        return $this;
    }
    
    private function getDoraPid($doi){
        
        return $pid;
    }
    
    public function update(){
        
    }
}