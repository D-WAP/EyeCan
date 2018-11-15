<!DOCTYPE html>
<html lang="en">
   <head>
	  <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
	  <meta http-equiv="Access-Control-Allow-Origin" content="*">
     
       <script src="http://ajax.googleapis.com/ajax/libs/jquery/2.0.0/jquery.min.js"></script>

      <title>EYE-SITE</title>
         <link rel="stylesheet" type="text/css" href="newStyle.css">
   </head>
   <body>
   

 	
 	 	 <form action="" method="get">
<br>
			  <input type="text" id="ip" class="ip" placeholder="Paste Your IP" style="margin-left: 100px"></input><br>

    <div class="col-md-5 col-sm-3 col-xs-6" style="margin-left: 400px;" > <a href="#" class="btn btn-sm animated-button victoria-two" id="D1-on"><img src="arrowup.png" height="100"><br>FORWARD</a> </div>
	 <div class="col-md-4 col-sm-3 col-xs-6" style="margin-left: 30px;" > <a href="#" class="btn btn-sm animated-button victoria-two" id="LEFT"><img src="arrowleft.png" height="100"><br>LEFT</a> </div>

    <div class="col-md-3 col-sm-3 col-xs-6" style="margin-left: 45px;" > <a href="#" class="btn btn-sm animated-button victoria-three" id="D1-off" ><img src="stop.png" height="100"><br>STOP</a> </div>
	 	 <div class="col-md-4 col-sm-3 col-xs-6" style="margin-left: 30px;"> <a href="#" class="btn btn-sm animated-button victoria-two" id="RIGHT"><img src="arrowright.png" height="100"><br>RIGHT</a> </div>
    <div class="separator"></div>
    <div class="col-md-5 col-sm-3 col-xs-6" style="margin-left: 400px;" > <a href="#" class="btn btn-sm animated-button victoria-four" id="D2-on"><img src="arrowdown.png" height="100"><br>BACKWARD</a> </div>
    <div class="separator3"></div>
			  <textarea id="logger" class="ip" placeholder="LOGS" readonly style="margin-left: 600px"></textarea>
        </form>
		<br><br>
	 </div>
	</div>
	


    </body>
    
	<script>
		document.getElementById('D1-on').addEventListener('click', function() {
				var ip = document.getElementById('ip').value;
				var url = "http://"+ ip + "/D1/1"
				var settings = {
				"async": true,
				"crossDomain": true,
				"url": url,
				"method": "GET",
				"headers": {
					"cache-control": "no-cache",
					'Content-Type' : 'application/x-www-form-urlencoded; charset=UTF-8'
					
					}
				}
				logger.textContent="\nD1 Turned ON\n" + document.getElementById("logger").value;
				$.ajax(settings).done(function (response) {
				});
		});
		document.getElementById('LEFT').addEventListener('click', function() {
				var ip = document.getElementById('ip').value;
				var url = "http://"+ ip + "/D3/1"
				var settings = {
				"async": true,
				"crossDomain": true,
				"url": url,
				"method": "GET",
				"headers": {
					"cache-control": "no-cache",
					'Content-Type' : 'application/x-www-form-urlencoded; charset=UTF-8'
					
					}
				}
				logger.textContent="\nD3 Turned ON\n" + document.getElementById("logger").value;
				$.ajax(settings).done(function (response) {
				});
		});
		

		document.getElementById('RIGHT').addEventListener('click', function() {
				var ip = document.getElementById('ip').value;
				var url = "http://"+ ip + "/D3/0"
				var settings = {
				"async": true,
				"crossDomain": true,
				"url": url,
				"method": "GET",
				"headers": {
					"cache-control": "no-cache",
					'Content-Type' : 'application/x-www-form-urlencoded; charset=UTF-8'
					
					}
				}
				logger.textContent="\nD3 Turned OFF\n" + document.getElementById("logger").value;
				$.ajax(settings).done(function (response) {
				});
		});

		document.getElementById('D1-off').addEventListener('click', function() {
				var ip = document.getElementById('ip').value;
				var url = "http://"+ ip + "/D1/0"
				var settings = {
				"async": true,
				"crossDomain": true,
				"url": url,
				"method": "GET",
				"headers": {
					"cache-control": "no-cache",
					'Content-Type' : 'application/x-www-form-urlencoded; charset=UTF-8'
					
					}
				}
				logger.textContent="\nD1 Turned OFF\n" + document.getElementById("logger").value;
				$.ajax(settings).done(function (response) {
				});
		});
		
		


		document.getElementById('D2-on').addEventListener('click', function() {
				var ip = document.getElementById('ip').value;
				var url = "http://"+ ip + "/D2/1"
				var settings = {
				"async": true,
				"crossDomain": true,
				"url": url,
				"method": "GET",
				"headers": {
					"cache-control": "no-cache",
					'Content-Type' : 'application/x-www-form-urlencoded; charset=UTF-8'
					
					}
				}
				logger.textContent="\nD2 Turned ON\n" + document.getElementById("logger").value;
				$.ajax(settings).done(function (response) {
				});
		});
		
		document.getElementById('D2-off').addEventListener('click', function() {
				var ip = document.getElementById('ip').value;
				var url = "http://"+ ip + "/D2/0"
				var settings = {
				"async": true,
				"crossDomain": true,
				"url": url,
				"method": "GET",
				"headers": {
					"cache-control": "no-cache",
					'Content-Type' : 'application/x-www-form-urlencoded; charset=UTF-8'
					
					}
				}
				logger.textContent="\nD2 Turned OFF\n" + document.getElementById("logger").value;
				$.ajax(settings).done(function (response) {
					console.log(response);
				});
		});
		
		
	</script>
</html>