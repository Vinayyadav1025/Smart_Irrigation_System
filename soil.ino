#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <ArduinoOTA.h>

const char* ssid = "Vinay";
const char* password = "12345678";
const char* serverUrl = "http://Your IP:3000/soil"; // Change the server URL to match your endpoint for touch sensor
int flag = 0;
int prev = 0;
const int relayPin = D1;  // GPIO pin for relay control
const int sensor_pin = D0; // Soil Sensor input at Analog PIN A0

void setup() {
  Serial.begin(115200);
  pinMode(relayPin, OUTPUT);
  pinMode(sensor_pin, INPUT);
  digitalWrite(relayPin, LOW);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize OTA
  ArduinoOTA.begin();
}

void loop() {
  // Handle OTA events
  ArduinoOTA.handle();


  // Read soil moisture sensor
  int moisturePercentage = digitalRead(sensor_pin);
  Serial.print("Moisture : ");
  Serial.print(moisturePercentage);
  Serial.println("%");
  // Control relay based on soil moisture level
  if (moisturePercentage == 0) {//pani bhara hai
    digitalWrite(relayPin, HIGH);
    prev = flag;
    flag = 0;
  } else {
    digitalWrite(relayPin, LOW);
    
    prev = flag;
    flag = 1;
  }

  if(flag != prev){
    sendTouchData(moisturePercentage);
  }
  delay(1000);
}

void sendTouchData(float moisturePercentage) {
  WiFiClient client;
  HTTPClient http;

  // Create a JSON object
  StaticJsonDocument<200> doc;
  doc["moisturePercentage"] = moisturePercentage;
  doc["status"] = "Moter has been started";
  // Serialize JSON to a string
  String jsonStr;
  serializeJson(doc, jsonStr);

  if (http.begin(client, serverUrl)) {
    http.addHeader("Content-Type", "application/json");

    // Send POST request with JSON payload
    int httpResponseCode = http.POST(jsonStr);
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.println("Error sending HTTP request");
    }
    http.end();
  } else {
    Serial.println("Failed to connect to server");
  }
}
