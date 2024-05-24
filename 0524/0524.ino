/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/


// notes in the melody:
#include "pitches.h"

// notes in the melody:
int melody_1[] = {
  NOTE_G5, NOTE_E5, NOTE_E5, 0, NOTE_F5, NOTE_D5,NOTE_D5, 0, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_G5, 0
};
int melody_2[] = {
  NOTE_C5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_G5, 0, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5, 0, 
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8
};

void setup() {
  pinMode(9, INPUT_PULLUP);
}

void loop() {
  // no need to repeat the melody.
   // iterate over the notes of the melody:
  int btn_state = digitalRead(9);
//  if(btn_state == HIGH){
//      noTone(8);
//    }


    for (int thisNote = 0; thisNote < 16; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    if(btn_state == HIGH)
    {
       int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody_1[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.50;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
    
    }
    else
    {
       int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody_2[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.50;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
    }
    }
}
   
  
