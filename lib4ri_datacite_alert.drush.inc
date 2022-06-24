<?php 

/**
 * Implements hook_drush_command().
 */

function lib4ri_datacite_alert_drush_command() {
    return array(
        'datacite' => array(
            'description' => dt('Datacite alert list update command'),
            'drupal_dependencies' => array('islandora', 'lib4ridora', 'lib4ri_pub_db'),
            'examples' => array('drush -u 1 -v datacite'),
            'options' => array(
                'start-date' => array('description' => dt('')),
                'end-date' => array('description' => dt('')),
            ),
        ),
    );
}

/**
 * Drush command.
 * drush_[MODULE_NAME]_[COMMAND_NAME]().
 */
function drush_lib4ri_datacite_alert_datacite() {
    module_load_include('inc', 'lib4ri_datacite_alert', 'includes/classes');
    
    $start_date = drush_get_option('start-date');
    $end_date = drush_get_option('end-date');
    
    if ($start_date Xor $end_date){
        echo "ERROR - Date range incomplete\n";
        exit();
    }
    
    $batch = array(
        'operations' => array(
            //            array('publication_DB_scopus_alert', array()),
        ),
        'finished' => 'lib4ri_datacite_batch_finished',
        'title' => t('Fetching Datacite info'),
        'init_message' => t('Starting...'),
        'progress_message' => t('Processed @current out of @total.'),
        'error_message' => t('Example Batch has encountered an error.'),
        'file' => drupal_get_path('module', 'lib4ri_datacite_alert') . '/lib4ri_datacite_alert.module',
    );
    $params = [];
    
    if ($start_date){
        $params[0] = $start_date;
        $params[1] = $end_date;
    }
    else{
        $params[0] = variable_get('lib4ri_datacite_alert_upd_start_date', $newdate);
        $params[1] = 'now';
    
        $newdate = date('Y-m-d', time()).'T00:00:00Z'; //today
        variable_set('lib4ri_datacite_alert_upd_start_date', $newdate);
    }
    
    array_push($batch['operations'], array('lib4ri_datacite_alert_fetch', array($params)));
    
    batch_set($batch);
    drush_backend_batch_process();
}