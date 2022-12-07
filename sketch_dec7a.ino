
#define BLYNK_TEMPLATE_ID "TMPLqAUp7TUb"
#define BLYNK_DEVICE_NAME "smart iot drop off and pick up parcel"
#define BLYNK_AUTH_TOKEN "a6Cko-lYewNANpNpuROIWyiu3waeuDnN"


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;


char ssid[] = "HUAWEI P20";
char pass[] = "nafza9494";

int IRSensor = 5;
int solenoid = 3;
int pbutton = 4;
int vpbutton = 0;

void setup() {
  Serial.begin(115200);
  pinMode(IRSensor, INPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  int sensorStatus = digitalRead(IRSensor);  // Set the GPIO as Input
  if (sensorStatus == 1)                     // Check if the pin high or not
  {
    // Trigger notification
    Serial.println("Item delivered");
    if (pbutton == 1) {
      if (vpbutton == 0) {
        digitalWrite(solenoidPin, HIGH);
        vpbutton == 1;
      } else {
        digitalWrite(solenoidPin, LOW);
        vpbutton == 0;
      }
    }
  }

  BLYNK_WRITE(V1) {
    int pinValue = param.asInt();

    if (pinValue == 1) {
      digitalWrite(solenoidPin, HIGH);
    } else if (pinValue == 0) {
      digitalWrite(solenoidPin, LOW);
    }
  }
