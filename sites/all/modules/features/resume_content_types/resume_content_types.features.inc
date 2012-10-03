<?php
/**
 * @file
 * resume_content_types.features.inc
 */

/**
 * Implements hook_node_info().
 */
function resume_content_types_node_info() {
  $items = array(
    'education' => array(
      'name' => t('Education'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('School name'),
      'help' => '',
    ),
    'employer' => array(
      'name' => t('Employer'),
      'base' => 'node_content',
      'description' => t('An employer for whom you worked'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'job' => array(
      'name' => t('Job'),
      'base' => 'node_content',
      'description' => t('A job position you held at a place of employment'),
      'has_title' => '1',
      'title_label' => t('Job Title'),
      'help' => '',
    ),
    'job_task' => array(
      'name' => t('Job Task'),
      'base' => 'node_content',
      'description' => t('A task, responsibility, or accomplishment you achieved at a job'),
      'has_title' => '1',
      'title_label' => t('Task'),
      'help' => '',
    ),
    'professional_organization' => array(
      'name' => t('Professional organization'),
      'base' => 'node_content',
      'description' => t('A group or professional organization'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('A project you worked on at a job'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'recommendation' => array(
      'name' => t('Recommendation'),
      'base' => 'node_content',
      'description' => t('A recommendation you received for work you performed at a job'),
      'has_title' => '1',
      'title_label' => t('Recommender'),
      'help' => '',
    ),
  );
  return $items;
}
