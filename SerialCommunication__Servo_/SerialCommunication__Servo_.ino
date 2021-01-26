#define SENSOR_PIN   A0
#define OUTPUT_PIN   9 //choose a pin for analog output (use a PWM pin)

#include <Servo.h>
Servo myservo;  // create servo object to control a servo

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);

  // Initialise the pins
  pinMode(SENSOR_PIN, INPUT);
  // pinMode(OUTPUT_PIN, OUTPUT);

  // Turn the output off
  analogWrite(OUTPUT_PIN, 0);

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
 
  readOwnSensor();
  receiveData();
  delay(15); //give the servo a breather


}

void receiveData(){
  
  // check if data has been received from the serial connection:
  if (Serial.available() > 0) {

    // take the reading
    int receivedReading = Serial.read();
    
    // Maybe some mapping needed here, depending on what your output needs.
    // You will always receive data that is 0-255 (a single byte)
    receivedReading = map(receivedReading, 0, 255, 0, 180);
    
    myservo.write(receivedReading);
    
  }

void readOwnSensor(){
  
  // Take reading from the sensor
  int sensorReading = analogRead(SENSOR_PIN);

  // Maybe some mapping needed here, depending on what values your sensor gives.
  // You must create an output that is 0-255 so it can be sent as a single byte.
  int readingToSend = map(sensorReading, 0, 1023, 0, 255);

  // Send it to the serial connection
  Serial.write(readingToSend);
  
}
