<h2><?php print $node->title; ?></h2>

<div class="row">

  <div class="lead span7">
  <?php print render($content['field_short_description']); ?>
  </div>
  
  <div class="span3">
  
  <div id="myCarousel" class="carousel slide">
  <!-- Carousel items -->
  <div class="carousel-inner">
    <?php
      foreach($content['field_images']['#items'] as $image) {
        $imgurl = image_style_url('large', $image['uri']);
        print '<div class="item"><img src="' . $imgurl . '" class="img-polaroid img-project pull-left"></div>';
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
