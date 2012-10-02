<?php

/**
 * Creates the projects page
 */
function ns_site_projects() {
  $page_content = array();
  
  $page_content['intro'] = array(
    '#type' => 'markup', 
    '#prefix' => '<div>',
    '#suffix' => '</div>',
    '#markup' => t("A collection of some of the recent projects I've worked on:"),
  );
  
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
  $row_num = 0;
  $row_name = 'row' . $row_num;
  
  foreach($projects as $project) {
    
    if($count % 2 == 0) {
      // Create a new row
      $page_content[$row_name] = array(
        '#type' => 'markup', 
        '#prefix' => '<div class="row-fluid">',
        '#suffix' => '</div>',
      );
    }
    
    $page_content[$row_name]['project' . $count] = array(
      '#type' => 'markup', 
      '#prefix' => '<div class="span6">',
      '#suffix' => '</div>',
    );
    
    $page_content[$row_name]['project' . $count]['title'] = array(
      '#type' => 'markup', 
      '#prefix' => '<h2>',
      '#suffix' => '</h2>',
      '#markup' => $project->title,
    );
  
    $page_content[$row_name]['project' . $count]['info'] = array(
      '#type' => 'markup', 
      '#prefix' => '<p class="lead">',
      '#suffix' => '</p>',
      '#markup' => $project->field_short_description_value,
    );
    
    if(isset($project->uri)) {
      $imgurl = image_style_url('thumbnail', $project->uri);
      $page_content[$row_name]['project' . $count]['title'] = array(
        '#type' => 'markup', 
        '#prefix' => '<h2>',
        '#suffix' => '</h2>',
        '#markup' => $project->title,
      );
    }
    
    $path = 'node/' . $project->nid;
    if(drupal_lookup_path('alias', $path)) {
      $path = drupal_lookup_path('alias', $path);
    }
    
    $page_content[$row_name]['project' . $count]['more'] = array(
      '#type' => 'markup', 
      '#prefix' => '<p>',
      '#suffix' => '</p>',
      '#markup' => '<a class="btn btn-small" href="' . $path . '">View details »</a>',
    );
    
    if($count % 2 != 0) {
      $row_num++;
      $row_name = 'row' . $row_num;
    }
    
    $count++;
  }
  
  return $page_content;
}