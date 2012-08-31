<?php

/**
 * Creates the projects page
 */
function ns_site_projects() {
  $content_array = array();
  $retval = '<div class="lead">';
  $retval .= t('A collection of some of the recent projects I have worked on');
  $retval .= '</div>';
  
  $query = db_select('node', 'n')
    ->fields('n', array('nid', 'title'))
    ->condition('n.type', 'project')
    ->condition('n.status', 1);
    
  $query->join('field_data_field_short_description', 'short', 'n.nid = short.entity_id');
  $query->addField('short', 'field_short_description_value');

  $query->leftJoin('field_data_field_images', 'images', 'n.nid = images.entity_id');
  $query->leftJoin('file_managed', 'files', 'images.field_images_fid = files.fid');
  $query->addField('files', 'uri');

  $results = $query->execute();
  $projects = $results->fetchAllAssoc('nid');
  
  $count = 0;
  
  foreach($projects as $project) {
    
    if($count % 2 == 0) {
      // Create a new row
      $retval .= '<div class="row">';
    }
    
    $retval .= '<div class="span5">';
    $retval .= '<h2>' . $project->title . '</h2>';

    $style = 'thumbnail';  // or any other custom image style you've created via /admin/config/media/image-styles
    $imgurl = image_style_url($style, $project->uri);

    $retval .= '<p><img src="' . $imgurl . '" class="img-polaroid img-project pull-left">' . $project->field_short_description_value . '</p>';
    
    $path = 'node/' . $project->nid;
    if(drupal_lookup_path('alias', $path)) {
      $path = drupal_lookup_path('alias', $path);
    }
    
    $retval .= '<p><a class="btn btn-small" href="' . $path . '">View details »</a></p>';
    $retval .= '</div>';
    
    if($count % 2 != 0) {
      // End the row
      $retval .= '</div>';
    }
    
    $count++;
  }
  
  return $retval;
}