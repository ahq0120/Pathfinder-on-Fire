#include <Adafruit_NeoPixel.h>
#define maxActiveLeds 10
#define LED_PIN     12
#define NUM_LEDS    74

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

int activeLeds[maxActiveLeds];
int ledIndex;
bool displayingPath = false;
/*
int smokeSensorPin1 = A0;
int smokeSensorPin2 = A1;
int smokeSensorPin3 = A2;
int smokeSensorPin4 = A3;
int smokeSensorPin5 = A4;
int smokeSensorPin6 = A5;
int smokeSensorPin7 = A7;
int smokeSensorPin8 = A8;
int smokeSensorPin9 = A9;
int smokeSensorPin10 = A10;
*/
void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show();
}

void displayPathLights(String path) {
  displayingPath = true;
  int activeLedsCount = 0;

  for (int i = 0; i < path.length() - 1; i++) {
      char currentRoom = path.charAt(i);
      char nextRoom = path.charAt(i + 1);

      if (currentRoom == 'A' && nextRoom == 'C') {
        int ledIndices[] = {32,31,30,29,28,27,26,25};
        int numLeds = sizeof(ledIndices) / sizeof(ledIndices[0]);

      for (int j = 0; j < numLeds; j++) {
        ledIndex = ledIndices[j];
        strip.setPixelColor(ledIndex, strip.Color(255, 0, 0));
        strip.show();
        delay(200);
        strip.setPixelColor(ledIndex, strip.Color(0, 0, 0));
        strip.show();
      }
    }
 else if (currentRoom == 'C' && nextRoom == 'H') {
    int ledIndices[] = {46,47,48,49,50};
    int numLeds = sizeof(ledIndices) / sizeof(ledIndices[0]);

    for (int j = 0; j < numLeds; j++) {
        ledIndex = ledIndices[j];
        strip.setPixelColor(ledIndex, strip.Color(255, 0, 0));
        strip.show();
        delay(200);
        strip.setPixelColor(ledIndex, strip.Color(0, 0, 0));
        strip.show();
      }
}
    else if (currentRoom == 'H' && nextRoom == 'G') {
    int ledIndices[] = {17,16,15,14,13};
    int numLeds = sizeof(ledIndices) / sizeof(ledIndices[0]);

    for (int j = 0; j < numLeds; j++) {
        ledIndex = ledIndices[j];
        strip.setPixelColor(ledIndex, strip.Color(255, 0, 0));
        strip.show();
        delay(200);
        strip.setPixelColor(ledIndex, strip.Color(0, 0, 0));
        strip.show();
      }
}
    else if (currentRoom == 'G' && nextRoom == 'K') {
    int ledIndices[] = {5,4,3,2,1,0};
    int numLeds = sizeof(ledIndices) / sizeof(ledIndices[0]);

    for (int j = 0; j < numLeds; j++) {
        ledIndex = ledIndices[j];
        strip.setPixelColor(ledIndex, strip.Color(255, 0, 0));
        strip.show();
        delay(200);
        strip.setPixelColor(ledIndex, strip.Color(0, 0, 0));
        strip.show();
      }
    }
    else if (currentRoom == 'A' && nextRoom == 'E') {
    int ledIndices[] = {35,36,37,38,39,40};
    int numLeds = sizeof(ledIndices) / sizeof(ledIndices[0]);

    for (int j = 0; j < numLeds; j++) {
        ledIndex = ledIndices[j];
        strip.setPixelColor(ledIndex, strip.Color(255, 0, 0));
        strip.show();
        delay(200);
        strip.setPixelColor(ledIndex, strip.Color(0, 0, 0));
        strip.show();
      }
    }
    else if (currentRoom == 'B' && nextRoom == 'C') {
    int ledIndices[] = {18,19,20,21,22,23,24};
    int numLeds = sizeof(ledIndices) / sizeof(ledIndices[0]);

    for (int j = 0; j < numLeds; j++) {
        ledIndex = ledIndices[j];
        strip.setPixelColor(ledIndex, strip.Color(255, 0, 0));
        strip.show();
        delay(200);
        strip.setPixelColor(ledIndex, strip.Color(0, 0, 0));
        strip.show();
      }
    }
    else if (currentRoom == 'C' && nextRoom == 'A') {
    int ledIndices[] = {27,28,29,30,31,32,33,34};
    int numLeds = sizeof(ledIndices) / sizeof(ledIndices[0]);

    for (int j = 0; j < numLeds; j++) {
        ledIndex = ledIndices[j];
        strip.setPixelColor(ledIndex, strip.Color(255, 0, 0));
        strip.show();
        delay(200);
        strip.setPixelColor(ledIndex, strip.Color(0, 0, 0));
        strip.show();
      }
    }
    
    else if (currentRoom == 'E' && nextRoom == 'A') {
    int ledIndices[] = {38,37,36,35,34,33};
    int numLeds = sizeof(ledIndices) / sizeof(ledIndices[0]);

    for (int j = 0; j < numLeds; j++) {
        ledIndex = ledIndices[j];
        strip.setPixelColor(ledIndex, strip.Color(255, 0, 0));
        strip.show();
        delay(200);
        strip.setPixelColor(ledIndex, strip.Color(0, 0, 0));
        strip.show();
      }
    }
    
    else if (currentRoom == 'E' && nextRoom == 'J') {
    int ledIndices[] = {73,72,71,70,69,68,67,66};
    int numLeds = sizeof(ledIndices) / sizeof(ledIndices[0]);

    for (int j = 0; j < numLeds; j++) {
        ledIndex = ledIndices[j];
        strip.setPixelColor(ledIndex, strip.Color(255, 0, 0));
        strip.show();
        delay(200);
        strip.setPixelColor(ledIndex, strip.Color(0, 0, 0));
        strip.show();
      }
    }
    else if (currentRoom == 'F' && nextRoom == 'G') {
    int ledIndices[] = {6,7,8,9,10,11,12};
    int numLeds = sizeof(ledIndices) / sizeof(ledIndices[0]);

    for (int j = 0; j < numLeds; j++) {
        ledIndex = ledIndices[j];
        strip.setPixelColor(ledIndex, strip.Color(255, 0, 0));
        strip.show();
        delay(200);
        strip.setPixelColor(ledIndex, strip.Color(0, 0, 0));
        strip.show();
      }
    }
    
    else if (currentRoom == 'G' && nextRoom == 'H') {
    int ledIndices[] = {15,16,17,18,19};
    int numLeds = sizeof(ledIndices) / sizeof(ledIndices[0]);

    for (int j = 0; j < numLeds; j++) {
        ledIndex = ledIndices[j];
        strip.setPixelColor(ledIndex, strip.Color(255, 0, 0));
        strip.show();
        delay(200);
        strip.setPixelColor(ledIndex, strip.Color(0, 0, 0));
        strip.show();
      }
    }
    else if (currentRoom == 'H' && nextRoom == 'C') {
    int ledIndices[] = {50,49,48,47,46};
    int numLeds = sizeof(ledIndices) / sizeof(ledIndices[0]);

    for (int j = 0; j < numLeds; j++) {
        ledIndex = ledIndices[j];
        strip.setPixelColor(ledIndex, strip.Color(255, 0, 0));
        strip.show();
        delay(200);
        strip.setPixelColor(ledIndex, strip.Color(0, 0, 0));
        strip.show();
      }
    }
    else if (currentRoom == 'H' && nextRoom == 'I') {
    int ledIndices[] = {52,53,54,55,56,57,58,59};
    int numLeds = sizeof(ledIndices) / sizeof(ledIndices[0]);

    for (int j = 0; j < numLeds; j++) {
        ledIndex = ledIndices[j];
        strip.setPixelColor(ledIndex, strip.Color(255, 0, 0));
        strip.show();
        delay(200);
        strip.setPixelColor(ledIndex, strip.Color(0, 0, 0));
        strip.show();
      }
    }
    else if (currentRoom == 'I' && nextRoom == 'H') {
    int ledIndices[] = {59,58,57,56,55,54,53,52,51,50};
    int numLeds = sizeof(ledIndices) / sizeof(ledIndices[0]);

    for (int j = 0; j < numLeds; j++) {
        ledIndex = ledIndices[j];
        strip.setPixelColor(ledIndex, strip.Color(255, 0, 0));
        strip.show();
        delay(200);
        strip.setPixelColor(ledIndex, strip.Color(0, 0, 0));
        strip.show();
      }
    }
    else if (currentRoom == 'I' && nextRoom == 'J') {
    int ledIndices[] = {60,61,62,63};
    int numLeds = sizeof(ledIndices) / sizeof(ledIndices[0]);

    for (int j = 0; j < numLeds; j++) {
        ledIndex = ledIndices[j];
        strip.setPixelColor(ledIndex, strip.Color(255, 0, 0));
        strip.show();
        delay(200);
        strip.setPixelColor(ledIndex, strip.Color(0, 0, 0));
        strip.show();
      }
    }
    else if (currentRoom == 'J' && nextRoom == 'E') {
    int ledIndices[] = {68,69,70,71,72,73,74,75};
    int numLeds = sizeof(ledIndices) / sizeof(ledIndices[0]);

    for (int j = 0; j < numLeds; j++) {
        ledIndex = ledIndices[j];
        strip.setPixelColor(ledIndex, strip.Color(255, 0, 0));
        strip.show();
        delay(200);
        strip.setPixelColor(ledIndex, strip.Color(0, 0, 0));
        strip.show();
      }
    }
    else if (currentRoom == 'J' && nextRoom == 'K') {
    int ledIndices[] = {64,65};
    int numLeds = sizeof(ledIndices) / sizeof(ledIndices[0]);

    for (int j = 0; j < numLeds; j++) {
        ledIndex = ledIndices[j];
        strip.setPixelColor(ledIndex, strip.Color(255, 0, 0));
        strip.show();
        delay(200);
        strip.setPixelColor(ledIndex, strip.Color(0, 0, 0));
        strip.show();
      }
    }
    else if (currentRoom == 'D' && nextRoom == 'E') {
    int ledIndices[] = {45,44,43,42,41,40,39};
    int numLeds = sizeof(ledIndices) / sizeof(ledIndices[0]);

    for (int j = 0; j < numLeds; j++) {
        ledIndex = ledIndices[j];
        strip.setPixelColor(ledIndex, strip.Color(255, 0, 0));
        strip.show();
        delay(200);
        strip.setPixelColor(ledIndex, strip.Color(0, 0, 0));
        strip.show();
      }
    }

  displayingPath = false;
}
}
void loop() {
  if (Serial.available() > 0) {
    String path = Serial.readString();
    displayPathLights(path);
  }
  /*
  int smokeValue1 = analogRead(smokeSensorPin1);
  int smokeValue2 = analogRead(smokeSensorPin2);
  int smokeValue3 = analogRead(smokeSensorPin3);
  int smokeValue4 = analogRead(smokeSensorPin4);
  int smokeValue5 = analogRead(smokeSensorPin5);
  int smokeValue6 = analogRead(smokeSensorPin6);
  int smokeValue7 = analogRead(smokeSensorPin7);
  int smokeValue8 = analogRead(smokeSensorPin8);
  int smokeValue9 = analogRead(smokeSensorPin9);
  int smokeValue10 = analogRead(smokeSensorPin10);

  
  if (smokeValue1 > 500) { 
    
    Serial.println("G"); 
  }
  if (smokeValue2 > 750) { 
    
    Serial.println("F"); 
  }
  if (smokeValue3 > 700) { 
    
    Serial.println("H"); 
  }
  if (smokeValue4 > 400) {// 
    
    Serial.println("I"); 
  }
  if (smokeValue5 > 600) { 
    
    Serial.println("J"); 
  }
  if (smokeValue6 > 700) {// 
    
    Serial.println("B"); 
  }
  if (smokeValue7 > 500) { 
    
    Serial.println("E"); 
  }
  if (smokeValue8 > 600) {// 
    
    Serial.println("C"); 
  }
  if (smokeValue9 > 600) {// 
    
    Serial.println("D"); 
  }
  if (smokeValue10 > 300) { 
   
    Serial.println("A"); 
  }*/
}


