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
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access datacite data';
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
  $handler->display->display_options['fields']['id']['separator'] = '';
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
  $handler->display->display_options['fields']['pid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['pid']['alter']['path'] = 'islandora/object/[pid]';
  $handler->display->display_options['fields']['pid']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['pid']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['pid']['alter']['strip_tags'] = TRUE;
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
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['url']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['target'] = '_blank';
  /* Field: Datacite alert: Remarks */
  $handler->display->display_options['fields']['remarks']['id'] = 'remarks';
  $handler->display->display_options['fields']['remarks']['table'] = 'lib4ri_datacite_alert_data';
  $handler->display->display_options['fields']['remarks']['field'] = 'remarks';
  /* Field: Edit remarks */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Edit remarks';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Edit remarks';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'islandora/datacite/remarks?id=[id]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Add to DORA */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Add to DORA';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Add to DORA';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'islandora/datacite/add/?PID=[pid]&DATADOI=[datadoi]&ID=[id]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Check status */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Check status';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'Check status';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['path'] = 'islandora/datacite/check/?PID=[pid]&DATADOI=[datadoi]&ID=[id]';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  /* Field: Do NOT add */
  $handler->display->display_options['fields']['nothing_3']['id'] = 'nothing_3';
  $handler->display->display_options['fields']['nothing_3']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_3']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_3']['ui_name'] = 'Do NOT add';
  $handler->display->display_options['fields']['nothing_3']['label'] = '';
  $handler->display->display_options['fields']['nothing_3']['alter']['text'] = 'Mark as \'Do NOT add\'';
  $handler->display->display_options['fields']['nothing_3']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_3']['alter']['path'] = 'islandora/datacite/blacklist/?ID=[id]&PID=[pid]&DATADOI=[datadoi]';
  $handler->display->display_options['fields']['nothing_3']['element_label_colon'] = FALSE;
  /* Filter criterion: Datacite alert: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'lib4ri_datacite_alert_data';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['status']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['group_info']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['group_info']['group_items'] = array(
      1 => array(
          'title' => 'In DORA',
          'operator' => '=',
          'value' => 'In DORA',
      ),
      2 => array(
          'title' => 'Do NOT add',
          'operator' => '=',
          'value' => 'Do NOT add',
      ),
      3 => array(
          'title' => 'NOT in DORA',
          'operator' => 'not',
          'value' => 'O',
      ),
  );
  
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
      t('Add to DORA'),
      t('Check status'),
      t('Mark as \'Do NOT add\''),
      t('Page'),
  );
  
  /*******************************************************************************************************/
    $views['lib4ri_datacite_alert'] = $view;
    
    
  /*******************************************************************************************************/
    $view = new view();
    $view->name = 'pub_datacite_packages';
    $view->description = '';
    $view->tag = 'default';
    $view->base_table = 'lib4ri_datacite_alert_data';
    $view->human_name = 'Pub datacite packages';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
    
    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'Datacite alert';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['access']['perm'] = 'access datacite data';
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
    /* Field: Datacite alert: DORA PID */
    $handler->display->display_options['fields']['pid']['id'] = 'pid';
    $handler->display->display_options['fields']['pid']['table'] = 'lib4ri_datacite_alert_data';
    $handler->display->display_options['fields']['pid']['field'] = 'pid';
    $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
    /* Field: Datacite alert: ID */
    $handler->display->display_options['fields']['id']['id'] = 'id';
    $handler->display->display_options['fields']['id']['table'] = 'lib4ri_datacite_alert_data';
    $handler->display->display_options['fields']['id']['field'] = 'id';
    $handler->display->display_options['fields']['id']['separator'] = '';
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
    $handler->display->display_options['fields']['url']['exclude'] = TRUE;
    $handler->display->display_options['fields']['url']['alter']['make_link'] = TRUE;
    $handler->display->display_options['fields']['url']['alter']['path'] = '[url]';
    $handler->display->display_options['fields']['url']['alter']['absolute'] = TRUE;
    $handler->display->display_options['fields']['url']['alter']['external'] = TRUE;
    $handler->display->display_options['fields']['url']['alter']['target'] = '_blank';
    /* Field: Datacite alert: Remarks */
    $handler->display->display_options['fields']['remarks']['id'] = 'remarks';
    $handler->display->display_options['fields']['remarks']['table'] = 'lib4ri_datacite_alert_data';
    $handler->display->display_options['fields']['remarks']['field'] = 'remarks';
    /* Field: Edit remarks */
    $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
    $handler->display->display_options['fields']['nothing']['table'] = 'views';
    $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
    $handler->display->display_options['fields']['nothing']['ui_name'] = 'Edit remarks';
    $handler->display->display_options['fields']['nothing']['label'] = '';
    $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Edit remarks';
    $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
    $handler->display->display_options['fields']['nothing']['alter']['path'] = 'islandora/datacite/remarks?id=[id]';
    $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
    /* Field: Add to DORA */
    $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
    $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
    $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
    $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Add to DORA';
    $handler->display->display_options['fields']['nothing_1']['label'] = '';
    $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Add to MODS';
    $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
    $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'islandora/datacite/add/?PID=[pid]&DATADOI=[datadoi]&ID=[id]';
    $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
    /* Field: Check status */
    $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
    $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
    $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
    $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Check status';
    $handler->display->display_options['fields']['nothing_2']['label'] = '';
    $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'Check status';
    $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = TRUE;
    $handler->display->display_options['fields']['nothing_2']['alter']['path'] = 'islandora/datacite/check/?PID=[pid]&DATADOI=[datadoi]&ID=[id]';
    $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
    /* Field: Do NOT add */
    $handler->display->display_options['fields']['nothing_3']['id'] = 'nothing_3';
    $handler->display->display_options['fields']['nothing_3']['table'] = 'views';
    $handler->display->display_options['fields']['nothing_3']['field'] = 'nothing';
    $handler->display->display_options['fields']['nothing_3']['ui_name'] = 'Do NOT add';
    $handler->display->display_options['fields']['nothing_3']['label'] = '';
    $handler->display->display_options['fields']['nothing_3']['alter']['text'] = 'Mark as \'Do NOT add\'';
    $handler->display->display_options['fields']['nothing_3']['alter']['make_link'] = TRUE;
    $handler->display->display_options['fields']['nothing_3']['alter']['path'] = 'islandora/datacite/blacklist/?ID=[id]&PID=[pid]&DATADOI=[datadoi]';
    $handler->display->display_options['fields']['nothing_3']['element_label_colon'] = FALSE;
    /* Filter criterion: Datacite alert: DORA PID */
    $handler->display->display_options['filters']['pid_1']['id'] = 'pid_1';
    $handler->display->display_options['filters']['pid_1']['table'] = 'lib4ri_datacite_alert_data';
    $handler->display->display_options['filters']['pid_1']['field'] = 'pid';
    
    /* Display: Page */
    $handler = $view->new_display('page', 'Page', 'page');
    $handler->display->display_options['path'] = 'admin/islandora/lib4ri_datacite_alert/pub-datacite';
    $translatables['pub_datacite_packages'] = array(
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
        t('DORA PID'),
        t('ID'),
        t('.'),
        t('Data DOI'),
        t('Relation'),
        t('Publisher'),
        t('Status'),
        t('Timestamp'),
        t('Data URL'),
        t('Remarks'),
        t('Edit remarks'),
        t('Add to MODS'),
        t('Check status'),
        t('Mark as \'Do NOT add\''),
        t('Page'),
    );
    
  /*******************************************************************************************************/
    $views['lib4ri_datacite_alert_pub'] = $view;
    
    return $views;
}