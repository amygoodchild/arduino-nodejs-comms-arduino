// Takes reading from sensor (e.g. LDR) and sends it over serial connection
// Looks for readings coming from the serial connection and sends it to an output (e.g. LED)

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
  readOwnSensor();
  receiveData();
}

void receiveData(){

  // check if data has been received from the serial connection:
  if (Serial.available() > 0) {
    
    // take the reading
    int receivedReading = Serial.read(); 

    // Maybe some mapping needed here, depending on what your output needs.
    // You will always receive data that is 0-255 (a single byte)
    receivedReading = map(receivedReading, 0, 255, 0, 1023);

    // Send recieved data to output (e.g. LED)
    analogWrite(OUTPUT_PIN, receivedReading);
  }
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
