<?php

/**
 * @file
 * Implementation of Rules hooks, giving default configurations.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function lib4ri_datacite_alert_default_rules_configuration() {
    $exported_rules = array();
    $exported_rules['rules_fetch_datacite_packages'] = '{ "rules_fetch_datacite_packages" : {
    "LABEL" : "Fetch Datacite packages",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "lib4ri_datacite_alert", "islandora" ],
    "ON" : { "islandora_object_ingested" : [] },
    "DO" : [
      { "lib4ri_datacite_alert_fetch_packages" : { "object" : [ "object" ] } }
    ]
  }
}';
    
    foreach ($exported_rules as $exported_rule) {
        $rule = rules_import($exported_rule);
        $configs[$rule->name] = $rule;
    }
    
    return $configs;
    
}