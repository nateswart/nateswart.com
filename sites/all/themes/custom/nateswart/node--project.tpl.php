<h2><?php print $node->title; ?></h2>

<div class="row">

  <div class="lead span7">
  <?php print render($content['field_short_description']); ?>
  </div>
  
  <div class="span3">
  <?php
    foreach($content['field_images']['#items'] as $image) {
      $imgurl = image_style_url('thumbnail', $image['uri']);
      print '<img src="' . $imgurl . '" class="img-polaroid img-project pull-left">';
    }
  ?>
  </div>
  
</div>

<?php print render($content['field_long_description']); ?>
