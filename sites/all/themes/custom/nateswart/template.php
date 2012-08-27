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
  $form['actions']['submit']['#attributes'] = array('class' => array('btn btn-large btn-primary pull-right'));
  

  // Modify the contact page
  $form['#prefix'] = '<div class="row"><div class="span4"><p>Find me on:<br>
  <a href="http://twitter.com/nateswart" class="sb twitter">Twitter</a> <small>Twitter</small><br>
  <a href="http://www.linkedin.com/in/nateswart" class="sb linkedin">LinkedIn</a> <small>Linked In</small><br><hr>
</p></div><div class="span6">';
  $form['#suffix'] = '</div></div>';
}

/**
 * Implements hook_css_alter()
 */
function nateswart_css_alter(&$css) { 
  // Remove all default styles
   unset($css[drupal_get_path('module','system').'/system.theme.css']); 
}