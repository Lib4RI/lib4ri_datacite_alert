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

    $actions['lib4ri_datacite_alert_delete_packages'] = array(
        'label' => t('Datacite packages deletion'),
        'group' => t('Lib4RI_Datacite'),
        'parameter' => array(
            'object' => array(
                'type' => 'text',
                'label' => t('Object ID'),
                'description' => t('The ID of the purged object.'),
            ),
        ),
    );
    
    return $actions;
}

function lib4ri_datacite_alert_fetch_packages($object){
    module_load_include('module', 'lib4ri_datacite_alert', '');
    
    $ntoadd = _lib4ri_datacite_alert_fetch_single_pub($object);
    
    if ($ntoadd > 1){
        drupal_set_message("$ntoadd data packages have been found for DORA object $object->Id. Please check the Data Packages Management page to ingest them.",'warning');
        return 0;
    }

    if ($ntoadd > 0){
        drupal_set_message("$ntoadd data package has been found for DORA object $object->Id. Please check the Data Packages Management page to ingest it.",'warning');
        return 0;
    }
    
    return 0;
}

function lib4ri_datacite_alert_delete_packages($pid){
    module_load_include('inc', 'lib4ri_datacite_alert', 'includes/classes');
    
    lib4ri_datacite_alert_delete_data($pid);
}