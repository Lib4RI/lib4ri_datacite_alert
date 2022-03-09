<?php
module_load_include('inc', 'lib4ri_datacite_alert', 'includes/define');

function lib4ri_datacite_alert_insert_data($item, $identifier){
    db_insert(LIB4RI_DATACITE_ALERT_DATA_TABLE)
    ->fields(array( 'datadoi'=>$item['doi'], 
                    'url'=>$item['url'], 
                    'publisher'=>substr($item['publisher'],0,255), 
                    'doi'=>$identifier['relatedIdentifier'],
                    'relation'=>$identifier['relationType'],
                    'tstmp' => REQUEST_TIME,))->execute();
    
    
}