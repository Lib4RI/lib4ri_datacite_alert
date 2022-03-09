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