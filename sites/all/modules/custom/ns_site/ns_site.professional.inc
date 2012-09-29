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
    '#prefix' => '<div class="lead span4">',
    '#suffix' => '</div>',
    '#markup' =>  t('I am a software engineer focused on open source web-based technologies.'),
  );
  
  //TODO: Get tags for overview
  //$page_content['top']['overview']['#markup'] .= '[load tags]';

    
  $page_content['top']['recommendation'] = array(
    '#type' => 'markup', 
    '#prefix' => '<div class="span6"><blockquote>',
    '#suffix' => '</blockquote></div>',
  );
  
  $recommendations = ns_site_professional_getrecommendations();
  
  if($recommendations) {
    $featured_id = array_rand($recommendations, 1);
    
    $page_content['top']['recommendation']['body'] = array(
      '#type' => 'markup', 
      '#prefix' => '<p>',
      '#suffix' => '</p>',
      '#markup' => '“' . $recommendations[$featured_id]->field_short_version_value . '”',
    );
    
    $page_content['top']['recommendation']['credit'] = array(
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
    $page_content['top']['recommendation']['modal'] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="modal fade" id="recommendationsModal" tabindex="-1">',
      '#suffix' => '</div>',
    );

    $page_content['top']['recommendation']['modal']['header'] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="modal-header"><h4>',
      '#suffix' => '</h4></div>',
      '#markup' => t('Recommendations'),
    );
    
    
    $page_content['top']['recommendation']['modal']['body'] = array(
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
      
      $page_content['top']['recommendation']['modal']['body'][] = $recommendation;
    }
    
    $page_content['top']['recommendation']['modal']['footer'] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="modal-footer">',
      '#suffix' => '</div>',
    );
    
    $page_content['top']['recommendation']['modal']['footer']['closebutton'] = array(
      '#type' => 'item',
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
  
  //TODO: Display education dynamically
  $page_content['middle']['education']['rit']['name'] = array(
    '#type' => 'markup',
    '#prefix' => '<h4>',
    '#suffix' => '</h4>',
    '#markup' => 'Rochester Institute of Technology',
  );
  
  $page_content['middle']['education']['rit']['degree'] = array(
    '#type' => 'markup',
    '#markup' => 'Bachelor of Science in Information Technology',
  );
  
  $page_content['middle']['education']['rit']['info'] = array(
    '#items' => array(
      '1996-2000', 
      'IT Student Organization President',
      'Undergraduate commencement speaker',
    ),
    '#theme' => 'item_list',
  );
  
  $page_content['middle']['groups'] = array(
    '#type' => 'markup',
    '#prefix' => '<div class="span4">',
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
    '#prefix' => '<div class="span10">',
    '#suffix' => '</div>',
  );
  /**
  $page_content['bottom']['experience']['header'] = array(
    '#type' => 'markup', 
    '#prefix' => '<h2>',
    '#suffix' => '</h2>',
    '#markup' => t('Experience'),
  ); 
  
  //! TODO: Get experiences from object model
  $page_content['bottom']['experience']['rodale']['intro'] = array(
    '#type' => 'markup', 
    '#prefix' => '<h4>',
    '#suffix' => '</h4>',
    '#markup' => t('Senior Drupal Application Developer<small> - Rodale, Inc</small>'),
  );
  
  $page_content['bottom']['experience']['rodale']['date'] = array(
    '#type' => 'markup',
    '#markup' => t('March 2012 - Current | Emmaus, PA'),
  );
  
  $page_content['bottom']['experience']['rodale']['list'] = array(
    '#items' => array(
      'Technical lead overseeing migration of runnersworld.com from Vignette to Drupal',
    ),
    '#theme' => 'item_list',
  );
  */
  
  $page_content['experience']['linkedin'] = array(
    '#type' => 'markup',
    '#prefix' => '<div class="span13 pull-right">',
    '#suffix' => '</div>',
    '#markup' => 'Until this page is complete, you may like to <a href="http://www.linkedin.com/in/nateswart">view my full LinkedIn profile</a>',
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
