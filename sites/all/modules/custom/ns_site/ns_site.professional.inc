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
  
  //! TODO: Get tags for overview
  //$page_content['top']['overview']['#markup'] .= '[load tags]';

    
  $page_content['top']['recommendation'] = array(
    '#type' => 'markup', 
    '#prefix' => '<div class="span6"><blockquote>',
    '#suffix' => '</blockquote></div>',
  );
  
  //! TODO: Get random recommendation
  $page_content['top']['recommendation']['body'] = array(
    '#type' => 'markup', 
    '#prefix' => '<p>',
    '#suffix' => '</p>',
    '#markup' => '“Nate always exceeded the expectations of Product Management. His attention to detail and desire to deliver quality product, made him a great asset to the company.”',
  );
  
  $page_content['top']['recommendation']['credit'] = array(
    '#type' => 'markup', 
    '#prefix' => '<small>',
    '#suffix' => '</small>',
    '#markup' => 'Erik Larson, Lenel Systems International',
  );
  
  //! TODO: Add a link
  /**
  $page_content['top']['recommendation']['more'] = array(
    '#type' => 'markup', 
    '#prefix' => '<button class="btn btn-small pull-right" type="button">',
    '#suffix' => '</button>',
    '#markup' => t('View all recommendations'),
  );
  */
  
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
  
  //! TODO: Display education dynamically
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
  $groups = array(
    l('Chautauqua Leadership Network', 'http://www.google.com'), 
    l('Lehigh Valley Drupal Users Group', 'http://www.google.com') . ' (founder)',
    'Individual member of the Drupal Association',
  );
  
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
  
  $retval = array();
  
  foreach($records as $group) {
    $link = l($group->field_website_title, $group->field_website_url);
    $note = t('(@note)', array('@note' => $group->field_note_value));
    
    $retval[] = $link . ' ' . $note;
  }
  
  return $retval;
}
