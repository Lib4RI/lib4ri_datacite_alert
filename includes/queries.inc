<?php
module_load_include('inc', 'lib4ri_datacite_alert', 'includes/define');

function lib4ri_datacite_alert_insert_data($item, $identifier){
    db_insert(LIB4RI_DATACITE_ALERT_DATA_TABLE)
    ->fields(array( 'datadoi'=>$item['doi'],
                    'url'=>$item['url'], 
                    'publisher'=>substr($item['publisher'],0,255), 
                    'doi'=>$identifier['relatedIdentifier'],
                    'pid'=>$identifier['pid'],
                    'relation'=>$identifier['relationType'],
                    'tstmp' => REQUEST_TIME,))->execute();
    
    
}

function lib4ri_datacite_alert_get_ids($item, $identifier, $any_related = FALSE){
    $q = db_select(LIB4RI_DATACITE_ALERT_DATA_TABLE,'f');
    $q->fields('f', array('id'))
    ->condition('datadoi', $item['doi'], '=');
    
    if ($any_related){
        $q->condition('pid', $identifier, '=');
    }
    else{
        $q->condition('doi', $identifier['relatedIdentifier'], '=');
        $q->condition('relation', $identifier['relationType'], '=');
    }   
    $res = $q->execute();
    
    $ids = [];
    foreach ($res as $id) {
        array_push($ids, $id);
    }
    return $ids;
}

function lib4ri_datacite_alert_update_remarks($data){
    db_update(LIB4RI_DATACITE_ALERT_DATA_TABLE)
    ->fields(array(
        'remarks' => $data['remarks'],
    ))
    ->condition('id', $data['id'], '=')
    ->execute();
}

function lib4ri_datacite_alert_get_remarks($id){
    $res = db_select(LIB4RI_DATACITE_ALERT_DATA_TABLE,'f')
    ->fields('f', array('remarks'))
    ->condition('id', $id, '=')
    ->execute();
    
    $remarks = [];
    foreach ($res as $remark) {
        array_push($remarks, $remark);
    }
    return $remarks[0]->remarks;
    
}

function lib4ri_datacite_alert_get_publisher_label($publisher){
    $res = db_select(LIB4RI_DATACITE_ALERT_PUBLISHERS_TABLE,'f')
    ->fields('f', array('label'))
    ->condition('publisher_string', $publisher, '=')
    ->execute();
    
    $labels = [];
    foreach ($res as $label) {
        array_push($labels, $label);
    }
    return $labels[0]->label;
    
}