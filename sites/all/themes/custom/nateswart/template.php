<?php

/**
 * Implements hook_js_alter()
 */
function nateswart_js_alter(&$javascript) {
  // Replace Drupal's built-in jQuery with the version required by Twitter Bootstrap
  $javascript['misc/jquery.js']['data'] = drupal_get_path('theme', 'nateswart').'/js/jquery.js';
}

/**
 * Implements hook_form_FORM_ID_alter()
 */
function nateswart_form_contact_site_form_alter(&$form, &$form_state, $form_id) {
  // Assign bootstrap classes to the submit button
  $form['actions']['submit']['#attributes'] = array('class' => array('btn btn-large pull-right'));

  // Modify the contact page
  $prefix = '<div class="row">';
  $prefix .= '<div class="span4">';
  $prefix .= '<p>Find me on:</p>';
  $prefix .= '<a href="http://twitter.com/nateswart" class="sb text twitter">Twitter</a>';
  $prefix .= '<a href="http://www.linkedin.com/in/nateswart" class="sb text linkedin">LinkedIn</a>';
  $prefix .= '<a href="http://www.flickr.com/photos/nateswartphoto/" class="sb text flickr">flickr</a>';
  $prefix .= '<a href="http://drupal.org/user/249748/" class="sb text drupal">Drupal</a>';
  $prefix .= '<a href="https://github.com/nateswart" class="sb text github">Github</a>';
  $prefix .= '<hr>';
  $prefix .= '</div>';
  $prefix .= '<div class="span6"><p>Send me email:</p>';
   
  $form['#prefix'] = $prefix;
  
  $suffix = '</div></div>';
  $form['#suffix'] = $suffix;
}

/**
 * Implements hook_css_alter()
 */
function nateswart_css_alter(&$css) { 
  // Remove all default styles
  unset($css[drupal_get_path('module','system').'/system.theme.css']); 
}