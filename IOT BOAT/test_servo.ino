/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"

// defines variables
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "UNLpGmhte30jkPYW85uClVg34NqDT_zO";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "khatamiburhan";
char pass[] = "123khatamii";

// Hardware Serial on Mega, Leonardo, Micro...
//#define EspSerial Serial1
#include <Servo.h>
Servo servo;
Servo servo1;
Servo servo2;
// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

WidgetLCD lcd(V1);

BLYNK_WRITE(V2)

{
  servo1.write(0);
  servo2.write(0);
}

BLYNK_WRITE(V3)

{

  servo1.write(337);
  servo2.write(337);

}
BLYNK_WRITE(V4)

{
  servo.write(90);
}

BLYNK_WRITE(V5)
{
servo.write(0);
}

BLYNK_WRITE(V6)
{
servo.write(45);
}
 
long duration;
int distance;
int safetyDistance;
long duration2;
int distance2;
int safetyDistance2;
const int trigPin = 11;
const int echoPin = 12;
const int trigPin2 = 10;
const int echoPin2 = 13;
const int relay = 8;
const int relay2 = 7;
int moto =3;
int moto2 = 5;
void setup()
{
  // Debug console
  Serial.begin(9600);

  delay(10);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
  servo.attach(9);
  servo1.attach(4);
  servo2.attach(6);
  
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(relay2, OUTPUT);
pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin2, INPUT);

 lcd.clear(); //Use it to clear the LCD Widget
  lcd.print(0, 0, "Distance in cm");
}

void loop()
{
  lcd.clear(); //Use it to clear the LCD Widget
  lcd.print(0, 0, "Distance in cm");
  Blynk.run();
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
safetyDistance = distance;

digitalWrite(trigPin2, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);

duration2 = pulseIn(echoPin2, HIGH);

// Calculating the distance
distance2= duration2*0.034/2;

safetyDistance2 = distance2;

if (safetyDistance <= 20 || safetyDistance2 <= 20){
  digitalWrite(relay, HIGH);
  
}
else{
  digitalWrite(relay, LOW);
  
}



// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.print("\t");
Serial.print(distance);
Serial.print("\t");
Serial.print("Distance2: ");
Serial.print("\t");
Serial.print(distance2);
Serial.print("\n");
lcd.print(7, 1, distance);
}
