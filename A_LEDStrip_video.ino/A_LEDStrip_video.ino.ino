// ********************************************************************
//
// Don't forget to install the Fastled library for this example to work
//
// ********************************************************************


// Adding the library
#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 5

// Define what pins you are using for data and clock line
#define DATA_PIN 2
#define CLOCK_PIN 3
int t;
int tim;
#define BRIGHTNESS  5
int buttonPin;
int secPin; //seconds pin
int minPin; //minutes pin
int run; //value that indicates button presses
int extra; //extra pulses caused by an imperfect split of time over numleds

// Define the array of leds
// Nothing to change here
CRGB leds[NUM_LEDS];

void setup() {

  // This is where we configure what LED strip we are using and what pins control it
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);
  
  run = 0; //starts stopped
  t=0; //time starts at 0s
  buttonPin = 7; //whatever pin your button is plugged into
  secPin = 8; //button that adds 1 second
  minPin = 9; //adds 60 seconds
  
  pinMode(buttonPin, INPUT);
  pinMode(secPin, INPUT);
  pinMode(minPin, INPUT);
  FastLED.setBrightness(BRIGHTNESS); //lower the brightness

}

void loop() {
  
  // check if the pushbutton is pressed. If it is, the digitalRead is HIGH
  if (digitalRead(buttonPin) == HIGH) {
    // turn timer on:
    run=255;}

  //timer runs
  if (run>0){
    leds[0]=CRGB::Red; //start indicator
    FastLED.show();
    delay(1500);
    
    extra = t%NUM_LEDS; //remainder of seconds
    
    for (int i = 0; i < NUM_LEDS; i++) { //for each LED
      tim = t/NUM_LEDS; //# of times the LED will blink
      
      if (extra>0){ //allocate the remainder amongst the LEDs
        tim=tim+1;
        extra=extra-1;}
    
      for (int j=0; j<tim; j++) { //have LED blink tim times
        leds[i] = CRGB::Black;
        FastLED.show();
        delay(500);
        leds[i] = CRGB::LavenderBlush;
        FastLED.show();
        delay(500);}}
   
    run=0;} //stop running

  //timer is not running, set time or blink
  else {
    while (digitalRead(minPin) == HIGH){ //add minutes to the time
      t=t+60;
      leds[1]=CRGB::Purple;
      FastLED.show();
      delay(500);
      leds[1]=CRGB::Black;
      FastLED.show();
      delay(500);}
      
    if (digitalRead(secPin) == HIGH){ //add seconds to the time
      t=t+1;
      leds[0]=CRGB::Blue;
      FastLED.show();
      delay(500);
      leds[0]=CRGB::Black;
      FastLED.show();
      delay(500);}
      
    else { //just blink until ready
      for (int i = 0; i < NUM_LEDS; i++) { //all green
        leds[i]=CRGB::Green;}
      FastLED.show();
      delay(2000);
      
      for (int i = 0; i < NUM_LEDS; i++) { //all off
        leds[i]=CRGB::Black;}
      FastLED.show();
      delay(1000);}
      }
     
     }    
      
    
