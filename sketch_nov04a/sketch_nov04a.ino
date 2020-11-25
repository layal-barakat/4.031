// ********************************************************************
//
// Don't forget to install the AccelStepper library for this example to work
// Library documentation here: https://www.airspayce.com/mikem/arduino/AccelStepper/
// Function reference here: https://www.airspayce.com/mikem/arduino/AccelStepper/classAccelStepper.html#adfb19e3cd2a028a1fe78131787604fd1
// Video that explains how the stepper works: https://www.youtube.com/watch?v=avrdDZD7qEQ&ab_channel=NikodemBartnik
//
// ********************************************************************


#include <AccelStepper.h>

///////
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int rev = 0;
/////////

#define STEP 4  // 4 for full step, 8 for half step, explanation here: https://www.motioncontrolonline.org/content-detail.cfm/Motion-Control-Application-Case-Studies/What-is-the-difference-between-full-stepping-the-half-stepping-and-the-micro-drive/content_id/3192

// Motor pin definitions
#define motorPin1  13     // IN1 on the ULN2003 driver 1
#define motorPin2  12     // IN2 on the ULN2003 driver 1
#define motorPin3  11     // IN3 on the ULN2003 driver 1
#define motorPin4  10     // IN4 on the ULN2003 driver 1

AccelStepper stepper1(STEP, motorPin1, motorPin3, motorPin2, motorPin4);


//////////////////////////////////////////////////////////////////
/// Use these  if you want to move a specific number of steps
//  This example moves a full rotation clockwise and then a full rotation counter-clockwise. Repeats.

int position = 2048; // this is the number of steps of a full rotation

void setup()
{  

  Serial.begin(9600);
  
   stepper1.setMaxSpeed(600);       // Sets the maximum permitted speed.  If your motors starts behaving erratically, lower this number. 600 seemed to be the limit for me.
   stepper1.setSpeed(400);         // Sets the speed. Positive numbers rotate clockwise. Negative numbers rotate counter-clockwise.
   myservo.attach(6);  // attaches the servo on pin 12 to the servo object
//   unsigned long previousMillis = 0;        // will store last time LED was updated
//   long OnTime = 250;           // milliseconds of on-time
//   long OffTime = 750;          // milliseconds of off-time
}

void loop()
{  

   stepper1.runSpeed();
   Serial.println(stepper1.currentPosition());
   Serial.println(pos);

//   // Flip rotation direction once done
//   if (stepper1.currentPosition() == position) {
//    stepper1.moveTo(0);
//   }
//   // Then flip again
//   if (stepper1.currentPosition() == 0) {
//    stepper1.moveTo(position);
//   }

   if (rev==0){ 
    if (pos==140) {
      rev=1;
      pos-=1;
      myservo.write(pos);
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
//   // check to see if it's time to change the state of the LED
//   unsigned long currentMillis = millis();
// 
//   if(currentMillis - previousMillis >= OnTime)
//   {
//     ledState = LOW;  // Turn it off
//     previousMillis = currentMillis;  // Remember the time
//     digitalWrite(ledPin, ledState);  // Update the actual LED
//   }

 //  myservo.write(pos);
   }  


/*
//////////////////////////////////////////////////////////////////
/// Use these instead if you are just looking for a constant speed motion

void setup()
{  
   stepper1.setMaxSpeed(600);       // Sets the maximum permitted speed.  If your motors starts behaving erratically, lower this number. 600 seemed to be the limit for me.
   stepper1.setSpeed(400);          // Sets the speed. Positive numbers rotate clockwise. Negative numbers rotate counter-clockwise.
}

void loop()
{  
   stepper1.runSpeed();
}
*/
