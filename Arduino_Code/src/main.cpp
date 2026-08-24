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
#define ONE_WIRE_BUS 2

// LED pins
const int LED_RED = 7;
const int LED_YELLOW = 4;



// Water quality indicator

// Depth detection
const int trigPin = 9;
const int echoPin = 8;
long duration;
int distance;

//TESTING ONLY
// TODO: add testing

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature sensors(&oneWire);

// Function declarations used before their definitions.
int detectDepth();
int calculateDepth();
int getTemp();

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

  // make a string for assembling the data to log:
  
  /*
  if (unsafe == true) {
    digitalWrite(LED_RED, HIGH);
  } 
  else if (testBlink == 1) {
    digitalWrite(LED_YELLOW, HIGH);
  }
  else{
    digitalWrite(LED_GREEN, HIGH);
  }
  */

  // Wait 0.1 second between each reading
  getTemp();
  delay(100);
}
/*
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
*/

int getTemp() {
  sensors.requestTemperatures(); 
   
  /* delay(); */
   
  float tempC = sensors.getTempCByIndex(0);
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println("°C");
  delay(100);

  return 0;
}