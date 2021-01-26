#define SENSOR_PIN   A0
#define OUTPUT_PIN   9


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

<<<<<<< Updated upstream
    // Maybe some mapping needed here
=======
    // Maybe some mapping needed here, depending on what your output needs...
    // (You will always receive data that is 0-255 (a single byte))
    // ...an analog output such as an LED will expect an analogWrite between 0-255
    //receivedReading = map(receivedReading, 0, 255, 0, 1023);
>>>>>>> Stashed changes

    // Use the reading for the output
    analogWrite(OUTPUT_PIN, reading);
  }
}
