<html lang="en">
  <head>
    <meta charset="utf-8">
    <title><?php print $head_title ?></title> 
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="">
    
    <!--[if lt IE 9]>
      <script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
    <![endif]-->
    
    <style>
      /* This style needs to be specified before the bootstrap responsive style */
      body {
        padding-top: 60px;
      }
    </style>
    
    <?php print $styles;?>
  </head>

  <body>

  <?php
    print $page_top;
    print $page;
    print $page_bottom;
    print $scripts;
  ?>
  
  </body>
</html>