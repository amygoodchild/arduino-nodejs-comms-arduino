#define SENSOR_PIN   A0
#define OUTPUT_PIN   D0


void setup() {
  // initialize the serial communication:
  Serial.begin(9600);

  // Initialise the pins
  pinMode(SENSOR_PIN, INPUT);
  pinMode(OUTPUT_PIN, OUTPUT);

  // Turn the output off
  analogWrite(OUTPUT_PIN, 0);
}

void loop() {

  // Take reading from the sensor
  int reading = analogRead(SENSOR_PIN);

  // Send it to the serial connection
  Serial.write(reading);


  // check if data has been received from the serial connection:
  if (Serial.available() > 0) {
    
    // take the reading
    int reading = Serial.read(); 

    // Maybe some mapping needed here

    // Use the reading for the output
    analogWrite(OUTPUT_PIN, reading);
  }
}