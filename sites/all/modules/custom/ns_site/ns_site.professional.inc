<?php

/**
 * Creates the professional page
 */
function ns_site_professional() {
  $page_content = array();
  
  /* Top row */
  $page_content['top'] = array(
    '#type' => 'markup', 
    '#prefix' => '<div class="row">',
    '#suffix' => '</div>',
  );

  $page_content['top']['overview'] = array(
    '#type' => 'markup', 
    '#prefix' => '<div class="lead span5">',
    '#suffix' => '</div>',
    '#markup' =>  t('I am a software engineer focused on open source web-based technologies.'),
  );
  
  //TODO: Get tags for overview
  //$page_content['top']['overview']['#markup'] .= '[load tags]';

    
  $page_content['top']['recommendation'] = array(
    '#type' => 'markup', 
    '#prefix' => '<div class="span6">',
    '#suffix' => '</div>',
  );
  
  $recommendations = ns_site_professional_getrecommendations();
  
  if($recommendations) {
    //TODO: Need to move this client-side if I expect it to work after heavy caching
    $featured_id = array_rand($recommendations, 1);
    
    $page_content['top']['recommendation']['body'] = array(
      '#type' => 'markup', 
      '#prefix' => '<blockquote>',
      '#suffix' => '</blockquote>',
    );
    
    $page_content['top']['recommendation']['body']['quote'] = array(
      '#type' => 'markup',
      '#prefix' => '<span class="lead">',
      '#suffix' => '</span>',
      '#markup' => '“' . $recommendations[$featured_id]->field_short_version_value . '”',
    );
    
    $page_content['top']['recommendation']['body']['credit'] = array(
      '#type' => 'markup', 
      '#prefix' => '<small>',
      '#suffix' => '</small>',
      '#markup' => $recommendations[$featured_id]->title 
        . ', ' . $recommendations[$featured_id]->field_recommender_title_value
        . ' (' . $recommendations[$featured_id]->field_recommender_company_value . ')',
    );
    
    $page_content['top']['recommendation']['more'] = array(
      '#type' => 'markup', 
      '#prefix' => '<a data-target="#recommendationsModal" class="btn btn-small pull-right" data-toggle="modal">',
      '#suffix' => '</a>',
      '#markup' => t('View all recommendations'),
    );
    
    
    // Build the mobile dialog for listing all recommendations
    //TODO: Apparently the bootstrap modal doesn't work on mobile?
    $page_content['modal'] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="modal fade" id="recommendationsModal" tabindex="-1" style="display: none;">',
      '#suffix' => '</div>',
    );

    //TODO: Fix this grossness
    $page_content['modal']['header'] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="modal-header"><h3>',
      '#suffix' => '<button type="button" class="close" data-dismiss="modal" aria-hidden="true">x</button></h3></div>',
      '#markup' => t('Recommendations'),
    );
    
    $page_content['modal']['body'] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="modal-body">',
      '#suffix' => '</div>',
    );
    
    foreach($recommendations as $rec) {
      $recommendation = array(
        '#type' => 'markup',
        '#prefix' => '<div>',
        '#suffix' => '</div>',
      );
      
      $recommendation['entry'] = array(
        '#type' => 'markup',
        '#prefix' => '<blockquote>"',
        '#suffix' => '"</blockquote>',
        '#markup' => $rec->field_full_version_value,
      );
      
      $recommendation['credit'] = array(
        '#type' => 'markup', 
        '#prefix' => '<small>',
        '#suffix' => '</small>',
        '#markup' => $rec->title 
          . ', ' . $rec->field_recommender_title_value
          . ' (' . $rec->field_recommender_company_value . ')',
      );
      
      $recommendation[] = array('#markup' => '<hr/>');
      
      $page_content['modal']['body'][] = $recommendation;
    }
    
    $page_content['modal']['footer'] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="modal-footer">',
      '#suffix' => '</div>',
    );
    
    $page_content['modal']['footer']['closebutton'] = array(
      '#type' => 'markup',
      '#prefix' => '<button class="btn btn-inverse" data-dismiss="modal">',
      '#suffix' => '</button>',
      '#markup' => t('Close'),
    );
  }
  
  
  $page_content[] = array('#markup' => '<hr/>');
  
  
  /* Middle row */
  $page_content['middle'] = array(
    '#type' => 'markup', 
    '#prefix' => '<div class="row">',
    '#suffix' => '</div>',
  );
  
  $page_content['middle']['education'] = array(
    '#type' => 'markup', 
    '#prefix' => '<div class="span6">',
    '#suffix' => '</div>',
  );
  
  $page_content['middle']['education']['header'] = array(
    '#type' => 'markup', 
    '#prefix' => '<h2>',
    '#suffix' => '</h2>',
    '#markup' => t('Education'),
  );
  
  
  //TODO: I need to rethink this education section
  $education = ns_site_professional_geteducation();

  foreach($education as $edu) {
    
    $edu_entry = array(
      '#type' => 'markup',
      '#prefix' => '<div>',
      '#suffix' => '</div>',
    );
    
    $edu_entry['name'] = array(
      '#type' => 'markup',
      '#prefix' => '<h4>',
      '#suffix' => '</h4>',
      '#markup' => $edu->title,
    );
    
    //TODO: I know there's a better way to output fields
    $edu_entry['degree'] = array(
      '#type' => 'markup',
      '#markup' => $edu->field_degree[$edu->language][0]['safe_value'] . ', ' . $edu->field_graduation_year[$edu->language][0]['safe_value'],
      '#prefix' => '<p class="lead"><small>',
      '#suffix' => '</small></p>',
    );
    
    $details = array();
    foreach($edu->field_details[$edu->language] as $detail) {
      $details[] = $detail['safe_value'];
    }
    
    $edu_entry['info'] = array(
      '#items' => $details,
      '#theme' => 'item_list',
    );
    
    $page_content['middle']['education'][] = $edu_entry;
  }
  
  $page_content['middle']['groups'] = array(
    '#type' => 'markup',
    '#prefix' => '<div class="span5">',
    '#suffix' => '</div>',
  );
  
  $page_content['middle']['groups']['header'] = array(
    '#type' => 'markup', 
    '#prefix' => '<h2>',
    '#suffix' => '</h2>',
    '#markup' => t('Groups'),
  );
    
  // Display groups/organizations  
  $groups = ns_site_professional_getorgs();
  
  $page_content['middle']['groups']['list'] = array(
    '#items' => $groups,
    '#theme' => 'item_list',
  );
  
  $page_content[] = array('#markup' => '<hr/>');
  
  
  /* Bottom row */
  $page_content['bottom'] = array(
    '#type' => 'markup', 
    '#prefix' => '<div class="row">',
    '#suffix' => '</div>',
  );
  
  $page_content['bottom']['experience'] = array(
    '#type' => 'markup', 
    '#prefix' => '<div class="span12">',
    '#suffix' => '</div>',
  );
  $page_content['bottom']['experience']['header'] = array(
    '#type' => 'markup', 
    '#prefix' => '<h2>',
    '#suffix' => '</h2>',
    '#markup' => t('Experience'),
  ); 
  
  $employers = ns_site_professional_getemployers();
  $experience = ns_site_professional_getexperience();
  
  foreach($experience as $job) {
    $job_entry = array(
      '#type' => 'markup', 
      '#prefix' => '<div class="span11 jobexperience">',
      '#suffix' => '</div>',
    );
    
    $job_entry['info'] = array(
      '#type' => 'markup', 
      '#prefix' => '<div class="pull-left span4">',
      '#suffix' => '</div>',
    );
    
    $employer_name = $employers[$job->field_employer_nid]->title;
        
    $job_entry['info']['intro'] = array(
      '#type' => 'markup', 
      '#prefix' => '<h4>',
      '#suffix' => '</h4>',
      '#markup' => $job->title,
    );
    
    
    $start_date = new DateTime($job->field_dates_value);
    $start_date = $start_date->format('F Y');
    
    $end_date = new DateTime($job->field_dates_value2);
    $end_date = $end_date->format('F Y');
    
    if($start_date === $end_date) {
      $end_date = t('Current');
    }
    
    $job_entry['info']['details'] = array(
      '#type' => 'markup', 
      '#prefix' => '<p class="lead"><small>',
      '#suffix' => '</small></p>',
      '#markup' => $employer_name . '<br>' . $start_date . ' - ' . $end_date,
    );
    


    
    //TODO: Add location display
      
    $tasks = ns_site_professional_getjobtasks($job->nid);
    
    $task_list = array();
    
    foreach($tasks as $task) {
      if($task->field_project_nid) {
        $task_list[] = l($task->title, 'node/' . $task->field_project_nid);
      }
      else {
        $task_list[] = $task->title;
      }
    } 
    
    $job_entry['list'] = array(
      '#items' => $task_list,
      '#theme' => 'item_list',
      '#prefix' => '<div class="span6">',
      '#suffix' => '</div>',
    );
        
    $page_content['bottom']['experience'][] = $job_entry;
  }
  
  $page_content[] = array('#markup' => '<hr/>');
  
  $page_content['linkedin'] = array(
    '#type' => 'markup',
    '#prefix' => '<div class="span2 pull-right">',
    '#suffix' => '</div>',
    '#markup' => '<a href="http://www.linkedin.com/in/nateswart">View my LinkedIn profile</a>',
  );
 
  return $page_content; 
}


function ns_site_professional_getrecommendations() {
  $query = db_select('node', 'n')
    ->fields('n', array('nid', 'title'))
    ->condition('type', 'recommendation')
    ->condition('status', 1);
    
  // Recommender title
  $query->join('field_data_field_recommender_title', 'rec_title', 'n.nid = rec_title.entity_id');
  $query->addField('rec_title', 'field_recommender_title_value');
  
  // Recommender company
  $query->join('field_data_field_recommender_company', 'rec_comp', 'n.nid = rec_comp.entity_id');
  $query->addField('rec_comp', 'field_recommender_company_value');
  
  // Short version
  $query->join('field_data_field_short_version', 'short_version', 'n.nid = short_version.entity_id');
  $query->addField('short_version', 'field_short_version_value');
  
  // Full version
  $query->join('field_data_field_full_version', 'full_version', 'n.nid = full_version.entity_id');
  $query->addField('full_version', 'field_full_version_value');
  
  $results = $query->execute();
  $records = $results->fetchAllAssoc('nid');
  
  return $records;
}


function ns_site_professional_geteducation() {
  $query = db_select('node', 'n')
    ->fields('n', array('nid', 'title'))
    ->condition('type', 'education')
    ->condition('status', 1);
  
  $results = $query->execute();
  $records = $results->fetchAllAssoc('nid');
  
  $nodes = node_load_multiple(array_keys($records));
  
  return $nodes;
}


function ns_site_professional_getorgs() {
  $query = db_select('node', 'n')
    ->fields('n', array('nid', 'title'))
    ->condition('type', 'professional_organization')
    ->condition('status', 1);
  
  // Website
  $query->join('field_data_field_website', 'website', 'n.nid = website.entity_id');
  $query->addField('website', 'field_website_title');
  $query->addField('website', 'field_website_url');
  
  // Note
  $query->join('field_data_field_note', 'note', 'n.nid = note.entity_id');
  $query->addField('note', 'field_note_value');
  
  $results = $query->execute();
  $records = $results->fetchAllAssoc('nid');
  
  $orgs = array();
  
  foreach($records as $group) {
    $link = l($group->field_website_title, $group->field_website_url);
    $note = t('<small class="muted">(@note)</small>', array('@note' => $group->field_note_value));
    $orgs[] = $link . ' ' . $note;
  }

  return $orgs;
}


function ns_site_professional_getexperience() {
  $query = db_select('node', 'n')
    ->fields('n', array('nid', 'title'))
    ->condition('type', 'job')
    ->condition('status', 1);
    
  // Dates
  $query->join('field_data_field_dates', 'dates', 'n.nid = dates.entity_id');
  $query->addField('dates', 'field_dates_value');
  $query->addField('dates', 'field_dates_value2');
  $query->orderBy('field_dates_value', 'DESC');
  
  // Employer
  $query->join('field_data_field_employer', 'emp', 'n.nid = emp.entity_id');
  $query->addfield('emp', 'field_employer_nid');
  
  $results = $query->execute();
  $records = $results->fetchAllAssoc('nid');
  
  //$nodes = node_load_multiple(array_keys($records));
  
  return $records;
}

function ns_site_professional_getemployers() {
  $query = db_select('node', 'n')
    ->fields('n', array('nid', 'title'))
    ->condition('type', 'employer')
    ->condition('status', 1);
  
  $results = $query->execute();
  $records = $results->fetchAllAssoc('nid');
  
  return $records;
}

function ns_site_professional_getjobtasks($job_id) {
  $query = db_select('node', 'n')
    ->fields('n', array('nid', 'title'))
    ->condition('type', 'job_task')
    ->condition('status', 1);
  
  // Job
  $query->join('field_data_field_job', 'job', 'n.nid = job.entity_id');
  $query->addfield('job', 'field_job_nid');
  $query->condition('job.field_job_nid', $job_id);
  
  // Project link
  $query->leftJoin('field_data_field_project', 'project', 'n.nid = project.entity_id');
  $query->addfield('project', 'field_project_nid');
  
  
  $results = $query->execute();
  $records = $results->fetchAllAssoc('nid');
  
  
  return $records;

}
