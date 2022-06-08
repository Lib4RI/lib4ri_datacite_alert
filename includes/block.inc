<?php
function lib4ri_datacite_alert_get_research_data_block_content($results) {
    module_load_include('inc', 'lib4ri_datacite_alert', 'includes/queries');
    
    $markup = array();
    foreach ($results as $key => $result) {
        if ($result != NULL){
            $publisher = $result->parentNode->getElementsByTagName('publisher')->item(0)->nodeValue;
        }
        else {
            break;
        }
 
        if ($results->length > 1){
            $doi_string = " ($result->nodeValue)";
        }
        else{
            $doi_string = "";
        }
        
        $label = lib4ri_datacite_alert_get_publisher_label($publisher);
        if (!$label){
            $label = $publisher;
        }
        
        $markup["research_$key"] = array(
            '#theme' => 'link',
            '#text' => t("View at ".$label.$doi_string),//format_plural(count($results), 'View Research Data', 'View Research Data (!count)', array('!count' => $key + 1)),
            '#path' => "https://doi.org/$result->nodeValue",//$result,
            '#options' => array(
                'attributes' => array('target' => '_blank'),
            ),
            "#prefix" => '<div title="'.$result->nodeValue.'" class="libfourri-research-data"><span>',
            '#suffix' => '</span></div>',
        );
    }
    return $markup;
}