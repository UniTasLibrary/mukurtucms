<?php
/**
 * @file
 * ma_dictionary.features.inc
 */

/**
 * Implements hook_default_cer().
 */
function ma_dictionary_default_cer() {
  $items = array();
  $items['node:dictionary_word:field_dictionary_word_synonyms*node:dictionary_word:field_dictionary_word_synonyms'] = entity_import('cer', '{
    "identifier" : "node:dictionary_word:field_dictionary_word_synonyms*node:dictionary_word:field_dictionary_word_synonyms",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:dictionary_word:field_dictionary_word_synonyms" } ] },
    "cer_right" : { "und" : [ { "path" : "node:dictionary_word:field_dictionary_word_synonyms" } ] },
    "rdf_mapping" : []
  }');
  $items['node:digital_heritage:field_related_dictionary_words*node:dictionary_word:field_dictionary_word_related_dh'] = entity_import('cer', '{
    "identifier" : "node:digital_heritage:field_related_dictionary_words*node:dictionary_word:field_dictionary_word_related_dh",
    "cer_bidirectional" : { "und" : [ { "value" : "1" } ] },
    "cer_enabled" : { "und" : [ { "value" : "1" } ] },
    "cer_weight" : { "und" : [ { "value" : "0" } ] },
    "cer_left" : { "und" : [ { "path" : "node:digital_heritage:field_related_dictionary_words" } ] },
    "cer_right" : { "und" : [ { "path" : "node:dictionary_word:field_dictionary_word_related_dh" } ] },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function ma_dictionary_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "scald" && $api == "context_config") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ma_dictionary_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ma_dictionary_node_info() {
  $items = array(
    'dictionary_word' => array(
      'name' => t('Dictionary Word'),
      'base' => 'node_content',
      'description' => t('Provide definitions, sample sentences, and audio/video for terms.'),
      'has_title' => '1',
      'title_label' => t('Term'),
      'help' => '',
    ),
    'language_community' => array(
      'name' => t('Language Community'),
      'base' => 'node_content',
      'description' => t('Language Community Groups are used to give users the ability to add and edit dictionary words for a given language.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function ma_dictionary_paragraphs_info() {
  $items = array(
    'dictionary_word_bundle' => array(
      'name' => 'Dictionary Word Bundle',
      'bundle' => 'dictionary_word_bundle',
      'locked' => '1',
    ),
  );
  return $items;
}