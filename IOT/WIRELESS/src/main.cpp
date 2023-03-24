//----------------------Skeleton Code--------------------//
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "ARUN_KUMAR"  // Replace with your network credentials
#define STAPSK  "arunkumar"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;
int X,Y,Z,F;

void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//

void setup(){
  OTAsetup();

  //-------------------//
  // Custom setup code //
  //-------------------//
  pinMode(2, INPUT);
  pinMode(4, INPUT);  
  pinMode(6, INPUT);  
  pinMode(8, OUTPUT);  
}

void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  //-------------------//
  X=digitalRead(2);
  Y=digitalRead(4);
  Z=digitalRead(6);
  F=Y||(X&&!Z);;
  digitalWrite(8, F);
}
