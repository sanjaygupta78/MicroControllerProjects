#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

const char* ssid = "ssid";
const char* password = "password";

int val;
int sensorPin = A0;
int buzzerPin = D1;

WiFiClient client;

unsigned long channel = 123123;
const char* apiKey = "apikey";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(10);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  val = analogRead(sensorPin);
  Serial.println(val);
  if (val > 150) {
    digitalWrite(buzzerPin, HIGH);
  }
  else {
    digitalWrite(buzzerPin, LOW);
  }
  ThingSpeak.writeField(channel, 1, val, apiKey);
  delay(15000);
}
