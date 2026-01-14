#include <Servo.h>

Servo myServo; 

const int inputPin = A0;
const int servoPin = 9;

float smallRMS = 0;
float bigRMS = 0;
float dataRMS = 0;

const int numSamples = 100;
const float adcResolution = 1023.0;
const float referenceVoltage = 5.0;



void setup() {
  pinMode(inputPin, INPUT);
  Serial.begin(115200);
  Serial.println("Send 'C' to calibrate.");

  myServo.attach(servoPin);   // attach the servo
  myServo.write(0);           // start at 0 degrees
}

float calculateRMS() {
  float sumSquares = 0;
  for (int i = 0; i < numSamples; i++) {
    int adcValue = analogRead(inputPin);
    float voltage = (adcValue / adcResolution) * referenceVoltage;
    sumSquares += voltage * voltage;
    delay(10);
  }
  return sqrt(sumSquares / numSamples);
}

void loop() {
  if (Serial.available() > 0) {
    char comByte = Serial.read();
    if (comByte == 'C') {
      Serial.println("Starting calibration...");

      Serial.println("Light flex in 3...");
      delay(1000);
      Serial.println("2...");
      delay(1000);
      Serial.println("1...");
      delay(1000);
      smallRMS = calculateRMS();
      Serial.print("Small RMS: ");
      Serial.println(smallRMS, 3);

      Serial.println("Hard flex in 3...");
      delay(1000);
      Serial.println("2...");
      delay(1000);
      Serial.println("1...");
      delay(1000);
      bigRMS = calculateRMS();
      Serial.print("Big RMS: ");
      Serial.println(bigRMS, 3);

      // Prevent divide by zero
      if (abs(bigRMS - smallRMS) < 0.01) {
        bigRMS += 0.01;
        Serial.println("Warning: RMS range too small, adjusted to avoid division by zero.");
      }
    }
  }

  float dataVoltage = (analogRead(inputPin) / adcResolution) * referenceVoltage;

  if (smallRMS != 0 && bigRMS != 0) {
    dataRMS = (dataVoltage - smallRMS) * (5.0 / (bigRMS - smallRMS));
    dataRMS = constrain(dataRMS, 0, 5);  // Clamp to expected range
  } else {
    dataRMS = 0;
  }

  // Map 0–5 V → 0–180 degrees
  float angle = 180.0 - (dataRMS / 5.0) * 180.0;
  angle = constrain(angle, 0, 180);

  myServo.write((int)angle);

  // Debug print
  Serial.print("dataRMS: ");
  Serial.print(dataRMS, 3);
  Serial.print("\tangle: ");
  Serial.println(angle, 1);
  

  delay(50);  // smooth update for plotter
}