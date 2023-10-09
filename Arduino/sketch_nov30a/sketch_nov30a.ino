#include<PubSub Client.h>
#include<ESP8266 WiFi.h>
#include<WiFi Client.h>
#include<ESP8266Web Server.h>
#define MAX_SRV_CLIENTS 3
#define mqtt_user**
#define mqtt_password**
 const char_ssid ="praveen";
 const char_password ="praveen123@";
 IPAddress addr ={
 IPAddress NMask={
 IPAddress gateway={
 IPAddress mqtt_server={
 WiFiClient wificlient;
 PubSub Client cilent(wificlient);
 void setup() {
   Serial.begin(9600);
   WiFi.config(addr,addr,NMask);
   WiFi.begin(ssid,password);
   Serial.print("\n connecting to:");
   Serial.println(ssid);
   while(WiFi status()!=WL_CONNECTED)
   {
     delay(500);
     Serial.print(".");
   }
   Serial.println("");
   Serial.println("WiFiconnected");
   Serial.println("IP address");
   Serial.println("WiFi.locallP());
   delay(26);
   cilent.set Server(mqtt_server,1883);
   delay(500);
   String strs ="";

 }
void loop() {
  if(!Client.connected());
  {
    reconnet();
  }
  byte byts =Serial.available();
  while(byts>0);
  {
    strs =Serial.readStringUntil("\n");
    client.loop();
    client.publish("eds/wndspl",String(strs).c_str().true);
    delay(100);
  }

}jjj
