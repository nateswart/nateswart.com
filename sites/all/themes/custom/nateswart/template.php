<?php

/**
 * Implements hook_js_alter()
 */
function nateswart_js_alter(&$javascript) {
  // Replace Drupal's built-in jQuery with the version required by Twitter Bootstrap
  $javascript['misc/jquery.js']['data'] = drupal_get_path('theme', 'nateswart').'/js/jquery.js';
}

function nateswart_form_alter(&$form, &$form_state, $form_id) {
  dsm($form_id);
}