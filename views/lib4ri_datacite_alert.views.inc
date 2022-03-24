<?php
/**
 * @file
 * Views hook implementations.
 */

/**
 * Implements hook_views_data().
 */
 
function lib4ri_datacite_alert_views_data() {
    module_load_include('inc', 'lib4ri_datacite_alert', 'includes/define');
    $data = array();
    // TODO: fix problems using define
    $data[LIB4RI_DATACITE_ALERT_DATA_TABLE] = array(
        'table' => array(
            'group' => t('Datacite alert'),
            'base' => array(
                'field' => 'id',
                'title' => t('Datacite alert'),
                'help' => t(''),
            ),
        ),  
        'id' => array(
            'title' => t('ID'),
            'help' => t(''),
            'field' => array(
                'handler' => 'views_handler_field_numeric',
                'click sortable' => TRUE,
            ),
            'filter' => array(
                'handler' => 'views_handler_filter_numeric',
            ),
            'sort' => array(
                'handler' => 'views_handler_sort',
            ),
        ),
        'tstmp' => array(
            'title' => t('Timestamp'),
            'help' => t(''),
            'field' => array(
                'handler' => 'views_handler_field_date',
                'click sortable' => TRUE,
            ),
            'sort' => array(
                'handler' => 'views_handler_sort_date',
            ),
            'filter' => array(
                'handler' => 'views_handler_filter_date',
            ),
        ),
        
        
        'doi' => array(
            'title' => t('DOI'),
            'help' => t(''),
            'field' => array(
                'handler' => 'views_handler_field_markup',
                'click sortable' => TRUE,
            ),
//             'filter' => array(
//                 'handler' => 'views_handler_filter_string',
//             ),
            
         ),
        
        'datadoi' => array(
            'title' => t('Data DOI'),
            'help' => t(''),
            'field' => array(
                'handler' => 'views_handler_field_markup',
                'click sortable' => TRUE,
            ),
            //             'filter' => array(
                //                 'handler' => 'views_handler_filter_string',
                //             ),
            
        ),
        
        'pid' => array(
            'title' => t('DORA PID'),
            'help' => t(''),
            'field' => array(
                'handler' => 'views_handler_field_markup',
                'click sortable' => TRUE,
            ),
            'filter' => array(
                'handler' => 'views_handler_filter_string',
            ),
//             'sort' => array(
//                 'handler' => 'views_handler_sort',
//             ),
        ),

        'url' => array(
            'title' => t('Data URL'),
            'help' => t(''),
            'field' => array(
                'handler' => 'views_handler_field_markup',
                'click sortable' => TRUE,
            ),
            //             'filter' => array(
            //                 'handler' => 'views_handler_filter_string',
            //             ),
            
        ),

        'publisher' => array(
            'title' => t('Publisher'),
            'help' => t(''),
            'field' => array(
                'handler' => 'views_handler_field_markup',
                'click sortable' => TRUE,
            ),
            //             'filter' => array(
            //                 'handler' => 'views_handler_filter_string',
            //             ),
            
        ),

        'relation' => array(
            'title' => t('Relation'),
            'help' => t(''),
            'field' => array(
                'handler' => 'views_handler_field_markup',
                'click sortable' => TRUE,
            ),
            //             'filter' => array(
            //                 'handler' => 'views_handler_filter_string',
            //             ),
            
        ),

        'status' => array(
            'title' => t('Status'),
            'help' => t(''),
            'field' => array(
                'handler' => 'views_handler_field_markup',
                'click sortable' => TRUE,
            ),
                        'filter' => array(
                            'handler' => 'views_handler_filter_string',
                        ),
            
        ),
        
        'remarks' => array(
            'title' => t('Remarks'),
            'help' => t(''),
            'field' => array(
                'handler' => 'views_handler_field_markup',
                'click sortable' => TRUE,
            ),
            //             'filter' => array(
            //                 'handler' => 'views_handler_filter_string',
            //             ),
            
        ),
        
        
        
     );
        
    return $data;
}
