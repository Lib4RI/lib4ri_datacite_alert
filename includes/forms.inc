<?php

 function lib4ri_datacite_alert_update_form(){
     $form['datacite_upd'] = array(
         '#name' => 'fetch_upd',
         '#type' => 'submit',
         '#value' => t('Fetch from Datacite'),
     );
    
     return $form;
 }
 
 function lib4ri_datacite_alert_update_form_submit(&$form, &$form_state){
    $clicked = $form_state['clicked_button']['#parents'][0];
    lib4ri_datacite_alert_batch($clicked);
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
     
     return $form;
 }
 
 /**
  * Implements hook_form_FORM_ID_alter().
  */
 
 function lib4ri_datacite_alert_form_lib4ri_datacite_alert_set_remarks_form_alter(&$form, &$form_state) {
     $id = trim($_GET['id'],'_');
     
     $form['lib4ri_datacite_alert_remarks']['#default_value'] = lib4ri_datacite_alert_get_remarks($id);
     
     return $form;
 }
 
 function lib4ri_datacite_alert_set_remarks_form_submit($form, &$form_state){
     $id = trim($_GET['id'],'_');
     
     if (!empty($id)){
         module_load_include('inc', 'lib4ri_datacite_alert', 'includes/queries');
         lib4ri_datacite_alert_update_remarks(array('remarks'=>$form_state['values']['lib4ri_datacite_alert_remarks'], 'id'=>$id));
     }
     drupal_goto('admin/islandora/lib4ri_datacite_alert/datacite-alert');
 }
 