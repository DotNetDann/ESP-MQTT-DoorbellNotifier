# ESP8266 MQTT Doorbell for HomeAssistant
This project allows is a modification in the 'ding dong' unit for the china doorbell
![alt text](https://github.com/DotNetDann/ESP-MQTT-DoorbellNotifier/blob/master/DoorbellListingPhoto.jpg?raw=true "Wiring Diagram")


#### Supported Features Include
- When somone rings your doorbell, a 'Ring' message gets sent to a MQTT broker
- Time has been taken to reduce power consumption of the ESP as this event is not that common and this is on 24/7
- Web page for status
- Over-the-Air (OTA) Upload from the ArduinoIDE!


#### OTA Uploading
This code also supports remote uploading to the ESP8266 using Arduino's OTA library. To utilize this, you'll need to first upload the sketch using the traditional USB method. However, if you need to update your code after that, your WIFI-connected ESP chip should show up as an option under Tools -> Port -> 'HostName'at your.ip.address.xxx. 

More information on OTA uploading can be found [here](http://esp8266.github.io/Arduino/versions/2.0.0/doc/ota_updates/ota_updates.html). 


#### Parts List
- [NodeMCU](https://www.amazon.com/HiLetgo-Version-NodeMCU-Internet-Development/dp/B010O1G1ES/)
- The doorbell - Search ebay for "WiFi Wireless Video Doorbell 8G"


#### Wiring Diagram
![alt text](https://github.com/DotNetDann/ESP-MQTT-DoorbellNotifier/blob/master/Wiring%20Diagram.png?raw=true "Wiring Diagram")
