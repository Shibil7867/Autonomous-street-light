#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "LbLjRZTcAWmgjaU8EFlXc2MNuGEzb-PE";
//char auth[] = "3gz9U19VowReglho02W6ke754x5Mdarl";// Enter your Blynk Auth Token here
char ssid[] = "OnePlus";   // Your WiFi SSID
char pass[] = "shibil123";  // Your WiFi password


#define LDR_PIN_1 36
#define LDR_PIN_2 39
#define LDR_PIN_3 34
#define LDR_PIN_4 35
#define LDR_PIN_5 32
#define LDR_PIN_6 33
#define IR_SENSOR_PIN 25
#define ldr 26

BlynkTimer timer;


void sendSensor(){
 
 int data1 = analogRead(LDR_PIN_1);
 int data2 = analogRead(LDR_PIN_2);
 int data3 = analogRead(LDR_PIN_3);
 int data4 = analogRead(LDR_PIN_4);
 int data5 = analogRead(LDR_PIN_5);
 int data6 = analogRead(LDR_PIN_6);
 int ldrValue = digitalRead(ldr);
 int irValue = digitalRead(IR_SENSOR_PIN);
 Blynk.virtualWrite(V0, data1);
 Blynk.virtualWrite(V1, data2);
 Blynk.virtualWrite(V2, data3);
 Blynk.virtualWrite(V3, data4);
 Blynk.virtualWrite(V4, data5);
 Blynk.virtualWrite(V5, data6);
  

  if(ldrValue == HIGH && irValue == LOW && data1 > 400){
    Blynk.logEvent("alert_streetlight1_not_fuctioning","Alert streetlight1 not fuctioning");
  }
  if(ldrValue == HIGH && irValue == LOW && data2 > 400){
    Blynk.logEvent("alert_streetlight2_not_fuctioning","Alert streetlight2 not fuctioning");
  }
  if(ldrValue == HIGH && irValue == LOW && data3 > 400){
    Blynk.logEvent("alert_streetlight3_not_fuctioning","Alert streetlight3 not fuctioning");
  }
  if(ldrValue == HIGH && irValue == LOW && data4 > 400){
    Blynk.logEvent("alert_streetlight1_not_fuctioning","Alert streetlight4 not fuctioning");
  }
  if(ldrValue == HIGH && irValue == LOW && data5 > 400){
    Blynk.logEvent("alert_streetlight2_not_fuctioning","Alert streetlight5 not fuctioning");
  }
  if(ldrValue == HIGH && irValue == LOW && data6 > 400){
    Blynk.logEvent("alert_streetlight3_not_fuctioning","Alert streetlight6 not fuctioning");
  }
  
}


void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
    
  // Initialize LDR pins as inputs
  pinMode(LDR_PIN_1, INPUT);
  pinMode(LDR_PIN_2, INPUT);
  pinMode(LDR_PIN_3, INPUT);
  pinMode(LDR_PIN_4, INPUT);
  pinMode(LDR_PIN_5, INPUT);
  pinMode(LDR_PIN_6, INPUT);

  // Initialize IR sensor pin and LED pins
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(ldr, INPUT);
  timer.setInterval(2500L, sendSensor);
  
}



void loop() {
  Blynk.run();
  timer.run();
  
  
}
