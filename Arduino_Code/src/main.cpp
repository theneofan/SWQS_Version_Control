#include <Arduino.h>
#include <math.h>

// SD card libraries
#include <SPI.h>
#include <SD.h>

// Temp sensor libraries
#include <OneWire.h>
#include <DallasTemperature.h>

// Ultrasonic Sensor
#include <NewPing.h>

// SD select pin
const int chipSelect = 10;

// Temp Sensor pin
const int oneWireBus = 2;

// LED pins
const int LED_RED = 7;
const int LED_YELLOW = 4;
const int LED_GREEN = 2;

// Water quality indicator
bool safe;
bool caution;
bool unsafe;

// Depth detection
const int trigPin = 9;
const int echoPin = 8;
long duration;
int distance;

//TESTING ONLY
int testBlink = 2;

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature sensors(&oneWire);

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // Open Serial communications
  Serial.begin(9600);
  // Wait for serial connection
  while(!Serial);

  Serial.print("setting up sd");

  if (!SD.begin(chipSelect)) {
    Serial.println("Setup Failed");
    Serial.println("Check sheild and card then reset board");
  }

  // Setup Sensors
  sensors.begin();

  Serial.println("Setup Complete");
}

void loop() {
  detectDepth();

  // make a string for assembling the data to log:
  String dataString = "";

  float tempC = sensors.getTempCByIndex(0);

  if (unsafe == true) {
    digitalWrite(LED_RED, HIGH);
  } 
  else if (testBlink == 1) {
    digitalWrite(LED_YELLOW, HIGH);
  }
  else{
    digitalWrite(LED_GREEN, HIGH);
  }


  // Wait 1 second between each reading

}

// put function definitions here:
int detectDepth() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Convert to cm
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
}

int calculateDepth() {


}