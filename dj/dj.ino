#include <MIDI.h>
#include <Encoder.h>  

#define ROTPOT1PIN A0
#define ROTPOT2PIN A1
#define ROTPOT3PIN A2
#define ROTPOT4PIN A3

#define SLIDEPOTPIN A5

MIDI_CREATE_DEFAULT_INSTANCE();


int rotPot1Val = 0;
int rotPot2Val = 0;
int rotPot3Val = 0;
int rotPot4Val = 0;
int slidePotVal = 0;
unsigned long previousMillis = millis();
unsigned long currentMillis = millis();

long encoder1_oldPosition  = -999;

Encoder encoder1(2, 3);

void setup() {
  MIDI.begin(4);
  Serial.begin(115200);
  

}

void loop() {
  long encoder1_newPosition = encoder1.read();
   if (encoder1_newPosition != encoder1_oldPosition) {
    encoder1_oldPosition = encoder1_newPosition;
    //Serial.print("[ encoder1_newPosition = ");
    //Serial.print(encoder1_newPosition);
    //Serial.print(" ]\n");
  }
  
  rotPot1Val = analogRead(ROTPOT1PIN);
  rotPot2Val = analogRead(ROTPOT2PIN);
  rotPot3Val = analogRead(ROTPOT3PIN);
  rotPot4Val = analogRead(ROTPOT4PIN);
  slidePotVal = analogRead(SLIDEPOTPIN);

  currentMillis = millis();
  if ((currentMillis - previousMillis) >= 50)
  {
    // Serial.print(" A0 = ");
    // Serial.print(rotPot1Val);
    // Serial.print(" A1 = ");
    // Serial.print(rotPot2Val);
    // Serial.print(" A2 = ");
    // Serial.print(rotPot3Val);
    // Serial.print(" A3 = ");
    // Serial.print(rotPot4Val);
    // Serial.print(" A5 = ");
    // Serial.print(slidePotVal);
    // Serial.print("\n");
    previousMillis = currentMillis;
    MIDI.sendControlChange(1, rotPot1Val, 1);
    MIDI.sendControlChange(1, rotPot2Val, 1);
    MIDI.sendControlChange(1, rotPot3Val, 1);
    MIDI.sendControlChange(1, rotPot4Val, 1);
    MIDI.sendControlChange(1, slidePotVal, 1);
  }
}
