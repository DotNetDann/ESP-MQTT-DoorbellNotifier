String GetDoorbellPic(bool Ringing) {
  
  String imgColor = "#666A70";
  if (Ringing) {
	  imgColor = "#009DDA";
  }
  
  String imgString = "<svg enable-background='new 0 0 365.888 174.819' version='1.1' viewBox='0 0 365.89 174.82' xml:space='preserve' xmlns='http://www.w3.org/2000/svg' width='365.888px' height='174.819px'>";
  imgString += "	<g fill='none' stroke-miterlimit='10'>";
  imgString += "			<path d='m78.83 155.97c0 5.118-4.188 9.306-9.306 9.306h-52.114c-5.119 0-9.306-4.188-9.306-9.306v-139.59c0-5.118 4.187-9.306 9.306-9.306h52.114c5.118 0 9.306 4.188 9.306 9.306v139.59z' stroke='" + imgColor + "' stroke-width='1.8359'/>";
  imgString += "			<path d='m73.477 150.27c0 4.507-3.687 8.196-8.195 8.196h-43.629c-4.509 0-8.196-3.689-8.196-8.196v-128.2c0-4.508 3.688-8.196 8.196-8.196h43.628c4.509 0 8.195 3.688 8.195 8.196v128.2z' stroke='" + imgColor + "' stroke-width='1.8359'/>";
  imgString += "			<path d='m51.027 88.225c0.32-0.322 0.518-0.762 0.518-1.252 0-0.487-0.199-0.931-0.518-1.25' stroke='" + imgColor + "' stroke-width='1.3191'/>";
  imgString += "			<path d='m52.276 89.475c0.642-0.642 1.036-1.525 1.036-2.502 0-0.976-0.395-1.86-1.036-2.5' stroke='" + imgColor + "' stroke-width='1.3191'/>";
  imgString += "			<path d='m53.526 90.724c0.962-0.96 1.554-2.285 1.554-3.751s-0.592-2.792-1.554-3.752' stroke='" + imgColor + "' stroke-width='1.3191'/>";
  imgString += "			<path d='m35.493 88.225c-0.319-0.322-0.518-0.762-0.518-1.252 0-0.487 0.202-0.931 0.518-1.25' stroke='" + imgColor + "' stroke-width='1.3191'/>";
  imgString += "			<path d='m34.244 89.475c-0.641-0.642-1.035-1.525-1.035-2.502 0-0.976 0.395-1.86 1.035-2.5' stroke='" + imgColor + "' stroke-width='1.3191'/>";
  imgString += "			<path d='m32.995 90.724c-0.961-0.96-1.555-2.285-1.555-3.751s0.594-2.792 1.555-3.752' stroke='" + imgColor + "' stroke-width='1.3191'/>";
  imgString += "			<path d='m43.468 94.914c-0.811 0-1.485-0.581-1.638-1.346h-0.631c0.157 1.111 1.113 1.971 2.269 1.971 1.154 0 2.11-0.859 2.268-1.971h-0.631c-0.153 0.765-0.828 1.346-1.637 1.346z' stroke='" + imgColor + "' stroke-width='1.6145'/>";
  imgString += "			<path d='m49.791 91.277c-1.42-1.171-1.434-1.799-1.473-3.66-0.01-0.387-0.018-0.823-0.041-1.322-0.126-2.618-1.575-4.561-3.655-5.086 0.299-0.296 0.485-0.708 0.485-1.163 0-0.904-0.735-1.639-1.64-1.639s-1.641 0.734-1.641 1.639c0 0.454 0.187 0.867 0.485 1.163-2.08 0.525-3.53 2.468-3.654 5.086-0.023 0.499-0.033 0.935-0.041 1.323-0.039 1.86-0.054 2.488-1.485 3.67-0.254 0.231-0.325 0.619-0.183 0.991 0.157 0.403 0.513 0.664 0.908 0.664h11.219c0.396 0 0.752-0.261 0.909-0.664 0.143-0.372 0.074-0.76-0.193-1.002zm-6.323-12.246c0.559 0 1.014 0.456 1.014 1.015 0 0.56-0.455 1.016-1.014 1.016-0.56 0-1.017-0.456-1.017-1.016 0-0.559 0.457-1.015 1.017-1.015zm5.934 13.021c-0.049 0.122-0.162 0.266-0.326 0.266h-11.219c-0.163 0-0.277-0.144-0.325-0.266-0.041-0.104-0.05-0.24 9e-3 -0.293 1.642-1.354 1.66-2.223 1.699-4.127 0.011-0.384 0.018-0.815 0.042-1.306 0.132-2.775 1.813-4.638 4.186-4.638 2.37 0 4.053 1.863 4.185 4.638 0.023 0.491 0.033 0.922 0.041 1.306 0.041 1.904 0.059 2.773 1.688 4.118 0.07 0.062 0.059 0.198 0.02 0.302z' stroke='" + imgColor + "' stroke-width='.8794'/>";
  imgString += "		<path d='m111.62 105.55c4.418-4.458 7.141-10.547 7.141-17.304 5e-3 -6.796-2.731-12.911-7.145-17.32' stroke='" + imgColor + "' stroke-width='1.8359'/>";
  imgString += "		<path d='m128.91 122.84c8.866-8.891 14.326-21.104 14.333-34.596 6e-3 -13.545-5.458-25.774-14.339-34.628' stroke='" + imgColor + "' stroke-width='1.8359'/>";
  imgString += "		<path d='m146.22 140.14c13.27-13.312 21.502-31.63 21.49-51.915 9e-3 -20.282-8.221-38.601-21.49-51.916' stroke='" + imgColor + "' stroke-width='1.8359'/>";
  imgString += "	</g>"; 
  imgString += "</svg>";
  return imgString;
}


void ServeWebClients() 
{
  String inString = F("<head><title>");
  inString += WIFI_HOSTNAME;
  inString += F("</title>");
  inString += F("<meta name='viewport' content='width=device-width, initial-scale=1'>");
  inString += F("<link rel='stylesheet' href='http://code.jquery.com/mobile/1.3.1/jquery.mobile-1.3.1.min.css' type='text/css'>");
  inString += F("<script src='http://code.jquery.com/jquery-1.9.1.min.js' type='text/javascript'></script>");
  inString += F("<script src='http://code.jquery.com/mobile/1.3.1/jquery.mobile-1.3.1.min.js' type='text/javascript'></script>");
  inString += F("</head>");
  inString += F("<body>");

  inString += F("<div data-role='page' id='page_opts'>");
  inString += F("<div data-role='header'><h3>");
  inString += WIFI_HOSTNAME;
  inString += F("</h3></div>");
  inString += F("<div data-role='content'>");

  inString += F("<fieldset data-role='controlgroup' data-type='horizontal'>");
  inString += F("<input type='radio' name='opt_group' id='basic' onclick='toggle_opt()' checked><label for='basic'>Info</label>");
  inString += F("<input type='radio' name='opt_group' id='other' onclick='toggle_opt()'><label for='other'>Settings</label>");
  inString += F("</fieldset>");
  
  
  inString += F("<div id='div_basic'>");
  inString += F("<h3 class='ui-bar ui-bar-a ui-corner-all'>Doorbell</h3>");

  inString += GetDoorbellPic(doorbelTriggered);

  inString += F("<tr><td><b>Doorbell&nbsp;State:</b></td><td><label id='lbl_rssi'");
  if (doorbelTriggered) {
    inString += F("style='color:blue;'>Waiting");
  } else {
    inString += F("style='color:red;'>RING");    
  }
  inString += F("</label></td></tr>");

  inString += F("</div>");

  
  inString += F("<div id='div_other' style='display:none;'>");
  inString += F("<table cellpadding='2'>");
  inString += F("<tr><td colspan='2'>&nbsp;</td></tr>");
  
  inString += F("<tr><td><b>WIFI SSID:</b></td><td><label id='lbl_rssi'>");
  inString += WIFI_SSID;
  inString += F("</label></td></tr>");

  inString += F("<tr><td><b>WiFi&nbsp;Signal:</b></td><td><label id='lbl_rssi'>");
  long rssi = WiFi.RSSI();
  if (rssi > -71) {
    inString += F("Good");
  } else if (rssi > -81) {
    inString += F("Weak");    
  } else {
    inString += F("Poor");    
  }
  inString += F(" (");
  inString += rssi;
  inString += F(" dbBm)");
  inString += F("</label></td></tr>");
  
  inString += F("<tr><td colspan='2'>&nbsp;</td></tr>");

  inString += F("<tr><td><b>MQTT Server:</b></td><td><label id='lbl_rssi'>");
  inString += MQTT_SERVER;
  inString += F("</label></td></tr>");
  
  inString += F("<tr><td colspan='2'>&nbsp;</td></tr>");

  //inString += F("<tr><td><b>Relay Active Timeout:</b></td><td><label id='lbl_rssi'>");
  //inString += RELAY_ACTIVE_TIMEOUT;
  //inString += F(" ms</label></td></tr>");
  
  //inString += F("<tr><td colspan='2'>&nbsp;</td></tr>");
  //inString += F("<tr><td colspan='2'><input type='checkbox' id='cb1' ");
  //inString += F("checked");
  //inString += F(" disabled><label for='cb1'>");
  //inString += DOOR1_ALIAS;
  //inString += F("</label></td></tr>");
    
  inString += F("</table>");
  inString += F("</div>");

  
  inString += F("<div data-role='footer' data-theme='c'><h5>");
  inString += VERSION;
  inString += F("</h5></div>");
  inString += F("</div>");

  inString += F("<script>");
  inString += F("function eval_cb(n)  {return $(n).is(':checked')?1:0;}");
  inString += F("function toggle_opt() {");
  inString += F("$('#div_basic').hide();");
  inString += F("$('#div_other').hide();");
  inString += F("if(eval_cb('#basic')) $('#div_basic').show();");
  inString += F("if(eval_cb('#other')) $('#div_other').show();");
  inString += F("};");
  inString += F("</script>");
  inString += F("</body>");

  server.send(200, "text/html", inString);
}
