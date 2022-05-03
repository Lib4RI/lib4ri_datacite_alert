<?php

 function lib4ri_datacite_alert_update_form(){
     
     $form['lib4ri_datacite_alert_upd_start'] = array(
         '#type' => 'textfield',
         '#title' => t('Starting fetch date'),
         '#default_value' => variable_get('lib4ri_datacite_alert_upd_start_date'),
         '#required' => FALSE,
     );

     $form['lib4ri_datacite_alert_upd_stop'] = array(
         '#type' => 'textfield',
         '#title' => t('Ending fetch date'),
         '#default_value' => 'now',
         '#required' => FALSE,
     );
     
     $form['datacite_upd'] = array(
         '#name' => 'fetch_upd',
         '#type' => 'submit',
         '#value' => t('Fetch from Datacite'),
     );
    
     return $form;
 }
 
 function lib4ri_datacite_alert_update_form_submit(&$form, &$form_state){
    $clicked = $form_state['clicked_button']['#parents'][0];
    $from = $form_state['values']['lib4ri_datacite_alert_upd_start'];
    $to   = $form_state['values']['lib4ri_datacite_alert_upd_stop'];
    $dates = [$from, $to];
    $newdate = date('Y-m-d', time()).'T00:00:00Z'; //today
    variable_set('lib4ri_datacite_alert_upd_start_date', $newdate);
    lib4ri_datacite_alert_batch($dates);
 }
 
 function lib4ri_datacite_alert_set_remarks_form($form, &$form_state){
     module_load_include('inc', 'lib4ri_datacite_alert', 'includes/queries');
     $form['lib4ri_datacite_alert_remarks'] = array(
         '#type' => 'textarea',
         '#title' => t('Remarks'),
         '#required' => FALSE,
     );
     
     $form['submit'] = array(
         '#type' => 'submit',
         '#value' => 'Insert',
     );
     
     $form['referer'] = array(
         '#type' => 'hidden',
     );
     
     return $form;
 }
 
 /**
  * Implements hook_form_FORM_ID_alter().
  */
 
 function lib4ri_datacite_alert_form_lib4ri_datacite_alert_set_remarks_form_alter(&$form, &$form_state) {
     $id = trim($_GET['id'],'_');
     
     $form['lib4ri_datacite_alert_remarks']['#default_value'] = lib4ri_datacite_alert_get_remarks($id);
     $form['referer']['#default_value'] = $_SERVER['HTTP_REFERER'];
     
     return $form;
 }
 
 function lib4ri_datacite_alert_set_remarks_form_submit($form, &$form_state){
     $id = trim($_GET['id'],'_');
     
     if (!empty($id)){
         module_load_include('inc', 'lib4ri_datacite_alert', 'includes/queries');
         lib4ri_datacite_alert_update_remarks(array('remarks'=>$form_state['values']['lib4ri_datacite_alert_remarks'], 'id'=>$id));
     }
     drupal_goto($form_state['values']['referer']);
 }
 