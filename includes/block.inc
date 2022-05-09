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
        $markup["research_$key"] = array(
            '#theme' => 'link',
            '#text' => t("View $result->nodeValue at ".lib4ri_datacite_alert_get_publisher_label($publisher)),//format_plural(count($results), 'View Research Data', 'View Research Data (!count)', array('!count' => $key + 1)),
            '#path' => "https://doi.org/$result->nodeValue",//$result,
            '#options' => array(
                'attributes' => array('target' => '_blank'),
            ),
            "#prefix" => '<div class="libfourri-research-data"><span>',
            '#suffix' => '</span></div>',
        );
    }
    return $markup;
}