<h2><?php print $node->title; ?></h2>

<div class="row">

  <div class="lead span5">
  <?php print render($content['field_short_description']); ?>
  </div>
  
  <div class="span5">
  
  <div id="myCarousel" class="carousel slide">
  <!-- Carousel items -->
  <div class="carousel-inner">
    <?php
      $count = 0;
      
      foreach($content['field_images']['#items'] as $image) {
        $imgurl = image_style_url('medium', $image['uri']);
        print '<div class="item';
        if(0 == $count) {
          print ' active';
        }
        print '"><img src="' . $imgurl . '" class="pull-left"></div>';
        $count++;
      }
    ?>
  </div>
  <!-- Carousel nav -->
  <a class="carousel-control left" href="#myCarousel" data-slide="prev">&lsaquo;</a>
  <a class="carousel-control right" href="#myCarousel" data-slide="next">&rsaquo;</a>
</div>


  
  </div>
  
</div>

<?php print render($content['field_long_description']); ?>
