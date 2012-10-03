<?php

/**
 * Creates the projects page
 */
function ns_site_projects() {
  $page_content = array();
  
  $page_content['intro'] = array(
    '#type' => 'markup', 
    '#prefix' => '<p class="lead">',
    '#suffix' => '</p>',
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
  $projects = array_values($projects);
  
  $count = 0;
  $row_num = 0;
  $row_name = 'row' . $row_num;
  
  // Process first 2 items in highlighted row
  $page_content[$row_name] = array(
    '#type' => 'markup', 
    '#prefix' => '<div class="row-fluid">',
    '#suffix' => '</div>',
  );
  
  if(count($projects) > 1) {
    $page_content[$row_name][] = ns_site_project_createproject(
      array(
        'class' => 'span6',
        'count' => 0,
        'title' => $projects[0]->title,
        'info' => $projects[0]->field_short_description_value,
        'nid' => $projects[0]->nid,
        'imgurl' => $projects[0]->uri, 
      ));
  }
  
  if(count($projects) > 2) { 
    $page_content[$row_name][] = ns_site_project_createproject(
    array(
      'class' => 'span6',
      'count' => 1,
      'title' => $projects[1]->title,
      'info' => $projects[1]->field_short_description_value,
      'nid' => $projects[1]->nid,
      'imgurl' => $projects[1]->uri,
    ));
  }
  
  $page_content[] = array('#markup' => '<hr>');
 
  // Process all other projects 3 in a row
  for($i=0; $i<count($projects)-2; $i++) {
    
    $curr = $i + 2;
    
    if($i % 3 == 0) {
      // Create a new row
      $row_num++;
      $row_name = 'row' . $row_num;
      $page_content[$row_name] = array(
        '#type' => 'markup', 
        '#prefix' => '<div class="row-fluid">',
        '#suffix' => '</div>',
      );
      $count++;
    }
    
    $page_content[$row_name][] = ns_site_project_createproject(
    array(
      'class' => 'span4',
      'count' => $curr,
      'title' => $projects[$curr]->title,
      'info' => $projects[$curr]->field_short_description_value,
      'nid' => $projects[$curr]->nid,
    ));
  }
    
  return $page_content;
}


function ns_site_project_createproject($data) {
  $retval = array(
    '#type' => 'markup', 
    '#prefix' => '<div class="' . $data['class'] . '">',
    '#suffix' => '</div>',
  );
  
  $retval['title'] = array(
    '#type' => 'markup', 
    '#prefix' => '<h4>',
    '#suffix' => '</h4>',
    '#markup' => $data['title'],
  );
  
  // Special case the larger display
  if('span6' == $data['class']) {
    $retval['title']['#prefix'] = '<h2>';
    $retval['title']['#suffix'] = '</h2>';
    
    if(isset($data['imgurl'])) {
      $img = image_style_url('thumbnail', $data['imgurl']);
      $retval['img'] = array(
        '#type' => 'markup',
        '#markup' => '<img src="' . $img .'" class="pull-right img-rounded img-project">', 
      ); 
      
      
      $img;
    }
  }
  
  $retval['info'] = array(
    '#type' => 'markup', 
    '#prefix' => '<p>',
    '#suffix' => '</p>',
    '#markup' => $data['info'],
  );
  
  // Special case the larger display
  if('span6' == $data['class']) {
    $retval['info']['#prefix'] = '<p class="lead">';
  }
  
  /*
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
  */
  
  $path = drupal_get_path_alias('node/' . $data['nid']);
  
  $retval['more'] = array(
    '#type' => 'markup', 
    '#prefix' => '<p>',
    '#suffix' => '</p>',
    '#markup' => '<a class="btn btn-small btn-project" href="' . $path . '">View details »</a>',
  );

  
  return $retval;
}