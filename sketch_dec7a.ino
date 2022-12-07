/*************************************************************

  You’ll need:
   - Blynk IoT app (download from App Store or Google Play)
   - ESP8266 board
   - Decide how to connect to Blynk
     (USB, Ethernet, Wi-Fi, Bluetooth, ...)

  There is a bunch of great example sketches included to show you how to get
  started. Think of them as LEGO bricks  and combine them as you wish.
  For example, take the Ethernet Shield sketch and combine it with the
  Servo example, or choose a USB sketch and add a code from SendData
  example.
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPLqAUp7TUb"
#define BLYNK_DEVICE_NAME "smart iot drop off and pick up parcel"
#define BLYNK_AUTH_TOKEN "a6Cko-lYewNANpNpuROIWyiu3waeuDnN"


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "HUAWEI P20";
char pass[] = "nafza9494";

int IRSensor = 5;
int solenoid = 3;
int pbutton = 4;
int vpbutton = 0;

void setup() {
  // Debug console
  Serial.begin(115200);
  pinMode(IRSensor, INPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop() {
  Blynk.run();
  int sensorStatus = digitalRead(IRSensor);  // Set the GPIO as Input
  if (sensorStatus == 1)                     // Check if the pin high or not
  {
    // Trigger notification
    Serial.println("Item delivered");  // print Motion Detected! on the serial monitor window
  }
  if (pbutton == 1) {
    if (vpbutton == 0) {
      digitalWrite(solenoidPin, HIGH);

    } else {
      digitalWrite(solenoidPin, LOW);
    }
  }

  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}

BLYNK_WRITE(V1) // this command is listening when something is written to V1
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  
  if (pinValue == 1){
      digitalWrite(solenoidPin, HIGH);
  } else if (pinValue == 0) {
      digitalWrite(solenoidPin, LOW);
  }
  

}
