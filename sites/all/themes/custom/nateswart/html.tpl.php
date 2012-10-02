<!DOCTYPE html>
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
  
  <!-- Piwik --> 
  <script type="text/javascript">
  var pkBaseURL = (("https:" == document.location.protocol) ? "https://stats.nateswart.com/" : "http://stats.nateswart.com/");
  document.write(unescape("%3Cscript src='" + pkBaseURL + "piwik.js' type='text/javascript'%3E%3C/script%3E"));
  </script><script type="text/javascript">
  try {
  var piwikTracker = Piwik.getTracker(pkBaseURL + "piwik.php", 3);
  piwikTracker.trackPageView();
  piwikTracker.enableLinkTracking();
  } catch( err ) {}
  </script><noscript><p><img src="http://stats.nateswart.com/piwik.php?idsite=3" style="border:0" alt="" /></p></noscript>
  <!-- End Piwik Tracking Code -->

  </body>
</html>