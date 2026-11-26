#include <ESP8266WiFi.h>
#include <KiwisIoT.h>
#include <DHT.h>

#define DHT_PIN D4
#define DHT_TYPE DHT11
#define MQ135_PIN A0

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";

KiwisIoT kiwisiot(ssid, pass, topic);

DHT dht(DHT_PIN, DHT_TYPE);

// Monitoring thresholds
const float TEMP_LIMIT = 40.0;
const float HUMIDITY_LIMIT = 75.0;
const int GAS_LIMIT = 450;

void setup() {
  Serial.begin(115200);

  dht.begin();

  pinMode(MQ135_PIN, INPUT);

  kiwisiot.begin();

  Serial.println("Restaurant Kitchen Monitoring Started");
}

void loop() {
  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {
    lastSend = millis();

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    int gasValue = analogRead(MQ135_PIN);

    if (isnan(temperature) || isnan(humidity)) {
      Serial.println("DHT sensor reading failed!");
      return;
    }

    String status = "KITCHEN NORMAL";

    if (temperature >= TEMP_LIMIT ||
        humidity >= HUMIDITY_LIMIT ||
        gasValue >= GAS_LIMIT) {
      status = "KITCHEN ALERT";
    }

    Serial.println("------------------------");

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.print("MQ-135 Reading: ");
    Serial.println(gasValue);

    Serial.print("Kitchen Status: ");
    Serial.println(status);

    // Send data to KiwisIoT
    kiwisiot.send("0", temperature);
    kiwisiot.send("1", humidity);
    kiwisiot.send("2", gasValue);
    kiwisiot.send("3", status);
  }
}