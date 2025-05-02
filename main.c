#define BLYNK_TEMPLATE_ID "YOUR_TEMPLEATE_ID_HERE"
#define BLYNK_TEMPLATE_NAME "Gas Leakage"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN_HERE"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wifi Username";  // type your wifi name
char pass[] = "Wifi Password";  // type your wifi password
int smokeA0 = A0;

BlynkTimer timer;

void sendSensor() {
  int data = analogRead(smokeA0);
  Blynk.virtualWrite(V0, data);
  Serial.print("Pin A0: ");
  Serial.println(data);

  if (data > 20) {
    // Gas leakage detected
    Blynk.logEvent("gas_alert", "Gas Leakage Detected");
  }
}

void setup() {
  pinMode(smokeA0, INPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  // Wait until Blynk is connected or timeout after 10 seconds
  unsigned long startAttemptTime = millis();
  while (!Blynk.connected()) {
    Blynk.run();
    if (millis() - startAttemptTime > 10000) {
      Serial.println("Failed to connect to Blynk server. Check network credentials or server availability.");
      break;
    }
  }

  timer.setInterval(2500L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
