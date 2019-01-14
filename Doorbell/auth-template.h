/* Add your keys & rename this file to auth.h */

#ifndef _AUTH_DETAILS
#define _AUTH_DETAILS

// Wifi Settings
#define WIFI_HOSTNAME "Doorbell"
#define WIFI_SSID "ssid"
#define WIFI_PASSWORD "password"

// MQTT Settings
#define MQTT_SERVER "mqtt server ip"
#define MQTT_USER ""
#define MQTT_PASSWORD ""
#define MQTT_PORT 1883
#define MQTT_AVAIL_TOPIC WIFI_HOSTNAME "/availability"

// OTA Settings for pushing updated software
#define OTApassword "ota password" //the password you will need to enter to upload remotely via the ArduinoIDE
#define OTAport 8266


#define MQTT_ACTION_TOPIC WIFI_HOSTNAME "/action"
#define MQTT_STATUS_TOPIC WIFI_HOSTNAME "/status"
#define DOORBELL_PIN 16 // D0 on ESP8266
#define SILENCE_PIN 2 // D4 on ESP8266

#endif
