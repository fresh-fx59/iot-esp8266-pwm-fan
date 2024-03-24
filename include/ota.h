#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>
#include <secret.h>

const char* host = "esp8266-webupdate";
const char* update_path = "/firmware";
const char* update_username = OTA_USER;
const char* update_password = OTA_PASSWORD;

ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;

void setupOta() {
  Serial.println();
  Serial.println("Setting up OTA...");

  MDNS.begin(host);

  httpUpdater.setup(&httpServer, update_path, update_username, update_password);
  httpServer.begin();

  MDNS.addService("http", "tcp", 80);
  Serial.printf("HTTPUpdateServer ready! Open http://%s.local%s in your browser and login with username '%s' and password '%s'\n", host, update_path, update_username, update_password);
  Serial.println("Setting up OTA... Done!");
}

void loopOta() {
  httpServer.handleClient();
  MDNS.update();
}