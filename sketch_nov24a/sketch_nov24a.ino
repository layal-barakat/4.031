// Include the Arduino Stepper Library
#include <Stepper.h>
#include <Servo.h>

// Define Servo
Servo myservo;  // create servo object to control a servo
unsigned long prev = 0;
const int interval = A1;
int movenum = 0;
int pos = 0;
int rev = 0;
int inter = 0;
 
// Define for Stepper
const int STEPS_PER_REV = 2048;
const int SPEED_CONTROL = A0;
 
// Create Instance of Stepper Class
// Specify Pins used for motor coils
// The pins used are 13, 12, 11, 10
// Connected to L298N Motor Driver In1, In2, In3, In4 
// Pins entered in sequence 1-2-3-4 for proper step sequencing
 
Stepper stepper_NEMA17(STEPS_PER_REV, 13, 12, 11, 10);
 
void setup() {
  Serial.begin(9600);
  myservo.attach(6);  // attaches the servo on pin 6 to the servo object
}
 
void loop() {
  //Serial.println("Hello");
  // read the sensor value:
  int sensorReading = analogRead(SPEED_CONTROL);
  Serial.println(sensorReading);
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0,1023, 5, 10);
  Serial.println(motorSpeed);

  // set the motor speed:
  if (motorSpeed > 0) {
    stepper_NEMA17.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    stepper_NEMA17.step(STEPS_PER_REV / 1000);
  }

  //check current time for servo
  //Serial.println(pos);
  int pot = analogRead(interval);
  //Serial.println(pot);
  // map it to a range from 0 to 100:
  int lendelay = map(pot, 0,1024, 7, 40);
  Serial.println(lendelay);
  // set the motor speed:
  if (lendelay > 0) {
    inter = lendelay;}
  unsigned long current = millis();
  if (lendelay>38){return;}
  if (current - prev >= inter) {
    // save the last time you blinked the LED
    prev = current;

    if (rev==0){ 
      if (pos==80) {
        rev=1;
        pos-=1;
        //myservo.write(pos);
    }
    else{pos+=1;}
   }
   else {
    if (pos==0){
      rev=0;
      pos+=1;
    }
    else{pos-=1;}
   }
    myservo.write(pos);}
  }
  
