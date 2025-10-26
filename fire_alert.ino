/***************************************************
 * 🔥 FIRE ALERT SYSTEM (ESP32 + BLYNK IoT)
 * -----------------------------------------------
 * Author: Atharva Tripathi
 * Description: Detects fire using a flame sensor,
 * activates buzzer + LED, and sends instant 
 * push notifications via Blynk IoT Cloud.
 ***************************************************/

#define BLYNK_TEMPLATE_ID "TMPL3_PDnMSWZ"
#define BLYNK_TEMPLATE_NAME "FIRE ALERT SYSTEM"
#define BLYNK_AUTH_TOKEN "iP0LCbOJpzfJZhR_c8iRDKEUbBKDF_37"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// 🔹 Replace with your Wi-Fi credentials
char ssid[] = "At";          // WiFi Name
char pass[] = "12345678";    // WiFi Password

// 🔹 Hardware pin definitions
#define FLAME_SENSOR 4
#define LED 2
#define BUZZER 5

// 🔹 Optional: Prevent multiple notifications per fire event
bool fireDetected = false;

void setup() {
  Serial.begin(115200);

  pinMode(FLAME_SENSOR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.println("Connecting to WiFi...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("✅ Connected to Blynk Cloud");
}

void loop() {
  Blynk.run();

  int fireState = digitalRead(FLAME_SENSOR);

  if (fireState == LOW) { // LOW means flame detected
    if (!fireDetected) {
      fireDetected = true;
      Serial.println("🔥 Fire Detected!");
      digitalWrite(LED, HIGH);
      digitalWrite(BUZZER, HIGH);

      // 🔔 Instant Push Notification
      Blynk.notify("🔥 Fire Detected in your system! Take immediate action!");
    }
  } else {
    if (fireDetected) {
      fireDetected = false;
      Serial.println("✅ Safe Area");
      digitalWrite(LED, LOW);
      digitalWrite(BUZZER, LOW);
    }
  }

  delay(500); // Check sensor twice per second
}
