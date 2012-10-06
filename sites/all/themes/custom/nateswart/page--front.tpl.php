/**
* @file
* Theme implementation for the front page
*/

<?php include_once('navbar.inc');?>

<div class="container">
  
  
  <div class="row-fluid">
    <div class="span6">
      <h1>Nate Swart</h1>
      <p class="lead">Senior Drupal Application Developer</p>
    </div>
  </div>
  <div class="row-fluid">
    <div class="span3">
      <small>
        I am an <a href="https://association.drupal.org/membership">individual member</a> of the <a href="https://association.drupal.org/">Drupal Association</a>, which fosters and supports the Drupal software project, the community and its growth.
      </small>
    </div>
  </div>
  
  <p>
    <?php print $messages; ?>
  </p>

</div> <!-- /container -->