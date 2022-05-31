<?php

function lib4ri_datacite_alert_rules_action_info() {
    $actions = array();
    
    $actions['lib4ri_datacite_alert_fetch_packages'] = array(
        'label' => t('Datacite packages fetch'),
        'group' => t('Lib4RI_Datacite'),
        'parameter' => array(
            'object' => array(
                'type' => 'islandora_object',
                'label' => t('Object'),
                'description' => t('A Tuque object for the Fedora object.'),
            ),
        ),
    );
       
    return $actions;
}

function lib4ri_datacite_alert_fetch_packages($object){
    module_load_include('module', 'lib4ri_datacite_alert', '');
    
    $ntoadd = _lib4ri_datacite_alert_fetch_single_pub($object);
    
    if ($ntoadd > 1){
        drupal_set_message("$ntoadd data packages have been found for DORA object $pid. Please check the Data Packages Management page to ingest them.",'status');
        return 0;
    }

    if ($ntoadd > 0){
        drupal_set_message("$ntoadd data package has been found for DORA object $pid. Please check the Data Packages Management page to ingest it.",'status');
        return 0;
    }
    
    return 0;
}