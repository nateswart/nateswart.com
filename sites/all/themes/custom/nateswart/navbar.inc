<div class="navbar navbar-inverse navbar-fixed-top">
  <div class="navbar-inner">
    
    <div class="container">
      <a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </a>
      <div class="nav-collapse collapse" style="height: 0px; ">
        <a class="brand" href="/"><?php echo $site_name; ?></a>
        <div class="nav-collapse collapse" style="height: 0px; ">
          <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('nav')))); ?>
        </div>
      </div><!--/.nav-collapse -->
    </div>
  </div>
</div>