/*
  To use this code you will need the following dependencies:

  - Support for the ESP8266 boards.
        - You can add it to the board manager by going to File -> Preference and pasting http://arduino.esp8266.com/stable/package_esp8266com_index.json into the Additional Board Managers URL field.
        - Next, download the ESP8266 dependencies by going to Tools -> Board -> Board Manager and searching for ESP8266 and installing it.

  - You will also need to download the follow libraries by going to Sketch -> Include Libraries -> Manage Libraries
      - PubSubClient
      - ArduinoJSON

*/
// 1.1 Get concept working

// ------------------------------
// ---- all config in auth.h ----
// ------------------------------
#define VERSION F("v1.1 - DoorbellMqtt - https://github.com/DotNetDann - http://dotnetdan.info")

#include <ArduinoJson.h> // Benoit Blanchon
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <PubSubClient.h> // Nick O'Leary
#include <ArduinoOTA.h>
#include <SimpleTimer.h> //https://github.com/jfturcot/SimpleTimer
#include "auth.h"


/**************************************** GLOBALS ***************************************/
const int BUFFER_SIZE = JSON_OBJECT_SIZE(10);
#define MQTT_MAX_PACKET_SIZE 512

char* birthMessage = "online";
const char* lwtMessage = "offline";

// Variables
bool doorbelTriggered = false;


/******************************** GLOBAL OBJECTS *******************************/

WiFiClient espClient;
PubSubClient client(espClient);
ESP8266WebServer server(80);
SimpleTimer timer;

#include "web.h"

/********************************** START SETUP *****************************************/
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);       // Initialize the LED_BUILTIN pin as an output (So it doesnt float as a LED is on this pin)
  digitalWrite(LED_BUILTIN, LOW);     // Turn the status LED on

  Serial.begin(115200);
  delay(10);
  Serial.println(F("Starting..."));

  // Setup GPIO Pins
  pinMode(DOORBELL_PIN, INPUT_PULLDOWN_16);
  pinMode(SILENCE_PIN, OUTPUT);
  
  setup_wifi();

  client.setServer(MQTT_SERVER, MQTT_PORT);
  client.setCallback(callback);

  server.on("/", ServeWebClients);
  server.begin();

  //OTA SETUP
  ArduinoOTA.setPort(OTAport);
  ArduinoOTA.setHostname(WIFI_HOSTNAME); // Hostname defaults to esp8266-[ChipID]
  ArduinoOTA.setPassword((const char *)OTApassword); // No authentication by default

  ArduinoOTA.onStart([]() {
    Serial.println("Starting");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();
  
  timer.setInterval(120000, checkIn);
  timer.setInterval(200, check_doorbell_status);

  Serial.println(F("Ready"));
  digitalWrite(LED_BUILTIN, HIGH);     // Turn the status LED off
}


/********************************** START SETUP WIFI *****************************************/
void setup_wifi() {
  delay(10);
  Serial.print(F("Connecting to SSID: "));
  Serial.println(WIFI_SSID);

  // We start by connecting to a WiFi network
  WiFi.mode(WIFI_STA);
  //wifi_set_sleep_type(LIGHT_SLEEP_T); // Enable light sleep
  WiFi.hostname(WIFI_HOSTNAME);

  if (WiFi.status() != WL_CONNECTED) {  // FIX FOR USING 2.3.0 CORE (only .begin if not connected)
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  }

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }

  Serial.println(F(""));
  Serial.println(F("WiFi connected"));
  Serial.print(F("IP address: "));
  Serial.println(WiFi.localIP());
}


/********************************** START CALLBACK *****************************************/
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.println(F(""));
  Serial.print(F("Message arrived ["));
  Serial.print(topic);
  Serial.print(F("] "));

  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  String topicToProcess = topic;
  payload[length] = '\0';
  String payloadToProcess = (char*)payload;

  // Action Command
  if (payloadToProcess == "MUTE") {
    Serial.print(F("Triggering MUTE Doorbell!"));
    digitalWrite(SILENCE_PIN, LOW);
    Serial.println(" -> DONE");
  }
  else if (payloadToProcess == "UNMUTE") {
    Serial.print(F("Triggering UNMUTE Doorbell!"));
    digitalWrite(SILENCE_PIN, HIGH);
    Serial.println(F(" -> DONE"));
  } else {
    Serial.println(F("Unknown command!"));
  }
}


/********************************** START SEND STATE *****************************************/
//void sendState(int door) {
//  //{"state":"open","occupied":unknown,"distance":12,"name":"Door 1"}
//  //{"state":"closed","occupied":true,"distance":1000,"name":"Door 2"}
//  //{"state":"closed","occupied":false,"distance":2350,"name":"Door 3"}
//
//  StaticJsonBuffer<BUFFER_SIZE> jsonBuffer;
//  JsonObject& root = jsonBuffer.createObject();
//
//
//  root["state"] = doorbelTriggered;
//
//  char buffer[root.measureLength() + 1];
//  root.printTo(buffer, sizeof(buffer));
//
//  Publish(topic, buffer);
//
//  // For HA. Cannot read JSON so send a simple state result also
//  char* extraTopicState = "/value";
//  char extraTopic[100];
//  snprintf(extraTopic, sizeof extraTopic, "%s%s", topic, extraTopicState);
//  Publish(extraTopic, doorState);
//}

void Publish(char* topic, char* message) {
  client.publish(topic, message, true);

  //Print what was sent to console
  Serial.println(F(""));
  Serial.print(F("Published ["));
  Serial.print(topic);
  Serial.print(F("] "));
  Serial.println(message);
}



/********************************** START RECONNECT *****************************************/
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print(F("Attempting MQTT connection..."));
    // Attempt to connect
    if (client.connect(WIFI_HOSTNAME, MQTT_USER, MQTT_PASSWORD, MQTT_AVAIL_TOPIC, 0, true, lwtMessage)) {
      Serial.println(F("connected"));

      // Publish the birth message on connect/reconnect
      Publish(MQTT_AVAIL_TOPIC, birthMessage);

      //// Subscribe to the action topics to listen for action messages
      //Serial.print(F("Subscribing to "));
      //Serial.print(MQTT_ACTION_TOPIC);
      //Serial.println(F("..."));
      //client.subscribe(MQTT_ACTION_TOPIC);
       
    } else {
      Serial.print(F("failed, rc="));
      Serial.print(client.state());
      Serial.println(F(" try again in 5 seconds"));
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


/********************************** START DOOR STATUS *****************************************/
void check_doorbell_status()
{
  if(digitalRead(DOORBELL_PIN) == 0 && doorbelTriggered == false)
  {
    Publish(MQTT_STATUS_TOPIC, "Ring");
    doorbelTriggered = true;
    timer.setTimeout(6000, resetTrigger); 
  }  
}

void resetTrigger()
{
  doorbelTriggered = false;
}

void checkIn()
{
  Publish(MQTT_STATUS_TOPIC, "OK");
}


/********************************** START MAIN LOOP *****************************************/
void loop() {

  if (!client.connected()) {
    reconnect();
  }

  unsigned long currentTime = millis();
  
  if (WiFi.status() != WL_CONNECTED) {
    delay(1);
    Serial.print(F("WIFI Disconnected. Attempting reconnection."));
    setup_wifi();
    return;
  }

  client.loop(); // Check MQTT

  ArduinoOTA.handle(); // Check OTA Firmware Updates

  server.handleClient(); // Check Web page requests

  timer.run();
  //check_doorbell_status(); // Check the sensors and publish any changes
  
  // We have enabled Light sleep so this delay should reduce the power used
  delay(500); // Works great but want to save more power
  //delay(1000);
  //delay(2000); // Missed some button presses
  
  //Serial.print(".");
}
