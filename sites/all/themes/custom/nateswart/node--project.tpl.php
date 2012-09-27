<h2><?php print $node->title; ?></h2>

<div class="row">

  <div class="lead span4">
  <?php 
    print render($content['field_short_description']); 
    print render($content['field_project_homepage']); 
    
  ?>
  </div>
  
  <div class="span6">
  
  <?php
    if(isset($content['field_images']['#items'])) {
      // Carousel items
      $count = 0;
      print '<div id="myCarousel" class="carousel slide">';
      print '<div class="carousel-inner">';
      foreach($content['field_images']['#items'] as $image) {
        $imgurl = image_style_url('medium', $image['uri']);
        print '<div class="item';
        if(0 == $count) {
          print ' active';
        }
        print '"><img src="' . $imgurl . '"></div>';
        $count++;
      }
      print '</div>';
      print '<a class="carousel-control left" href="#myCarousel" data-slide="prev">&lsaquo;</a>';
      print '<a class="carousel-control right" href="#myCarousel" data-slide="next">&rsaquo;</a>';
      print '</div>';
    }
  ?>

  </div>
  
</div>


<div class="row">
  <div>
    <?php print render($content['field_long_description']); ?>
  </div>
</div>