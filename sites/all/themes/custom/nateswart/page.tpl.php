<?php 

include_once('navbar.inc');?>

<div class="container">
  <h1><?php print nateswart_get_display_title(); ?></h1>

  <div class="hero-unit">
  <?php 
    print $messages;
    print render($page['content']); 
  ?>
  </div>

</div> <!-- /container -->