<?php

/**
 * @file
 * Default views hook.
 */

/**
 * Implements hook_views_default_views().
 */
function lib4ri_datacite_alert_views_default_views() {
  $views = array();
  /*******************************************************************************************************/

    $view = new view();
    $view->name = 'datacite_alert';
    $view->description = '';
    $view->tag = 'default';
    $view->base_table = 'lib4ri_datacite_alert_data';
    $view->human_name = 'Datacite alert';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
    
    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'Datacite alert';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['access']['type'] = 'none';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = '50';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['pager']['options']['id'] = '0';
    $handler->display->display_options['pager']['options']['quantity'] = '9';
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
      'id' => 'id',
      'datadoi' => 'datadoi',
      'relation' => 'relation',
      'doi' => 'doi',
      'pid' => 'pid',
      'publisher' => 'publisher',
      'remarks' => 'remarks',
      'status' => 'status',
      'tstmp' => 'tstmp',
      'url' => 'url',
    );
    $handler->display->display_options['style_options']['default'] = '-1';
    $handler->display->display_options['style_options']['info'] = array(
      'id' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'datadoi' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'relation' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'doi' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'pid' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'publisher' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'remarks' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'status' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'tstmp' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'url' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
    );
    /* Field: Datacite alert: ID */
    $handler->display->display_options['fields']['id']['id'] = 'id';
    $handler->display->display_options['fields']['id']['table'] = 'lib4ri_datacite_alert_data';
    $handler->display->display_options['fields']['id']['field'] = 'id';
    /* Field: Datacite alert: Data DOI */
    $handler->display->display_options['fields']['datadoi']['id'] = 'datadoi';
    $handler->display->display_options['fields']['datadoi']['table'] = 'lib4ri_datacite_alert_data';
    $handler->display->display_options['fields']['datadoi']['field'] = 'datadoi';
    $handler->display->display_options['fields']['datadoi']['alter']['make_link'] = TRUE;
    $handler->display->display_options['fields']['datadoi']['alter']['path'] = 'http://dx.doi.org/[datadoi]';
    $handler->display->display_options['fields']['datadoi']['alter']['target'] = '_blank';
    /* Field: Datacite alert: Relation */
    $handler->display->display_options['fields']['relation']['id'] = 'relation';
    $handler->display->display_options['fields']['relation']['table'] = 'lib4ri_datacite_alert_data';
    $handler->display->display_options['fields']['relation']['field'] = 'relation';
    /* Field: Datacite alert: DOI */
    $handler->display->display_options['fields']['doi']['id'] = 'doi';
    $handler->display->display_options['fields']['doi']['table'] = 'lib4ri_datacite_alert_data';
    $handler->display->display_options['fields']['doi']['field'] = 'doi';
    $handler->display->display_options['fields']['doi']['alter']['make_link'] = TRUE;
    $handler->display->display_options['fields']['doi']['alter']['path'] = 'http://dx.doi.org/[doi]';
    $handler->display->display_options['fields']['doi']['alter']['target'] = '_blank';
    /* Field: Datacite alert: DORA PID */
    $handler->display->display_options['fields']['pid']['id'] = 'pid';
    $handler->display->display_options['fields']['pid']['table'] = 'lib4ri_datacite_alert_data';
    $handler->display->display_options['fields']['pid']['field'] = 'pid';
    /* Field: Datacite alert: Publisher */
    $handler->display->display_options['fields']['publisher']['id'] = 'publisher';
    $handler->display->display_options['fields']['publisher']['table'] = 'lib4ri_datacite_alert_data';
    $handler->display->display_options['fields']['publisher']['field'] = 'publisher';
    /* Field: Datacite alert: Status */
    $handler->display->display_options['fields']['status']['id'] = 'status';
    $handler->display->display_options['fields']['status']['table'] = 'lib4ri_datacite_alert_data';
    $handler->display->display_options['fields']['status']['field'] = 'status';
    /* Field: Datacite alert: Timestamp */
    $handler->display->display_options['fields']['tstmp']['id'] = 'tstmp';
    $handler->display->display_options['fields']['tstmp']['table'] = 'lib4ri_datacite_alert_data';
    $handler->display->display_options['fields']['tstmp']['field'] = 'tstmp';
    $handler->display->display_options['fields']['tstmp']['date_format'] = 'long';
    $handler->display->display_options['fields']['tstmp']['second_date_format'] = 'long';
    /* Field: Datacite alert: Data URL */
    $handler->display->display_options['fields']['url']['id'] = 'url';
    $handler->display->display_options['fields']['url']['table'] = 'lib4ri_datacite_alert_data';
    $handler->display->display_options['fields']['url']['field'] = 'url';
    $handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
    $handler->display->display_options['fields']['url']['alter']['path'] = '[url]';
    $handler->display->display_options['fields']['url']['alter']['absolute'] = TRUE;
    $handler->display->display_options['fields']['url']['alter']['external'] = TRUE;
    $handler->display->display_options['fields']['url']['alter']['target'] = '_blank';
    /* Field: Datacite alert: Remarks */
    $handler->display->display_options['fields']['remarks']['id'] = 'remarks';
    $handler->display->display_options['fields']['remarks']['table'] = 'lib4ri_datacite_alert_data';
    $handler->display->display_options['fields']['remarks']['field'] = 'remarks';
    /* Field: Global: Custom text */
    $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
    $handler->display->display_options['fields']['nothing']['table'] = 'views';
    $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
    $handler->display->display_options['fields']['nothing']['label'] = '';
    $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Edit remarks';
    $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
    $handler->display->display_options['fields']['nothing']['alter']['path'] = 'islandora/datacite/remarks?id=[id]';
    $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
    
    /* Display: Page */
    $handler = $view->new_display('page', 'Page', 'page');
    $handler->display->display_options['path'] = 'admin/islandora/lib4ri_datacite_alert/datacite-alert';
    $translatables['datacite_alert'] = array(
      t('Master'),
      t('Datacite alert'),
      t('more'),
      t('Apply'),
      t('Reset'),
      t('Sort by'),
      t('Asc'),
      t('Desc'),
      t('Items per page'),
      t('- All -'),
      t('Offset'),
      t('« first'),
      t('‹ previous'),
      t('next ›'),
      t('last »'),
      t('ID'),
      t('.'),
      t(','),
      t('Data DOI'),
      t('Relation'),
      t('DOI'),
      t('DORA PID'),
      t('Publisher'),
      t('Status'),
      t('Timestamp'),
      t('Data URL'),
      t('Remarks'),
      t('Edit remarks'),
      t('Page'),
    );
    /*******************************************************************************************************/
    $views['protein_db'] = $view;
    
    return $views;
}