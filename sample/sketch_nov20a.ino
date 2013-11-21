#include "c:\work\notetype.h"
#define BEEP 250

int t = 0;
int speakerPin = 3;

_notes notes[86] = {
  {1, 330, BEEP},
  {1, 330, BEEP},
  {0,   0, BEEP},
  {1, 330, BEEP},
  {0,   0, BEEP},
  {1, 262, BEEP},
  {1, 330, BEEP},
  {0,   0, BEEP},
  {1, 392, BEEP},
  {0,   0, BEEP*3},
  {1, 196, BEEP*2},
  {1, 1975, 75},
  {1, 2637, 75},
  {0,   0, BEEP},
  {1, 523, BEEP},
  {0,   0, BEEP*2},
  {1, 392, BEEP},
  {0,   0, BEEP*2},
  {1, 330, BEEP},
  {0,   0, BEEP*2},
  {1, 440, BEEP},
  {0,   0, BEEP},
  {1, 494, BEEP},
  {0,   0, BEEP},
  {1, 466, BEEP},
  {1, 440, BEEP},
  {0,   0, BEEP},
  {1, 392, BEEP},
  {1, 659, BEEP},
  {0,   0, BEEP},
  {1, 784, BEEP},
  {1, 880, BEEP},
  {0,   0, BEEP},
  {1, 698, BEEP},
  {1, 784, BEEP},
  {0,   0, BEEP},
  {1, 659, BEEP},
  {0,   0, BEEP},
  {1, 523, BEEP},
  {1, 587, BEEP},
  {1, 494, 2*BEEP},
  {1, 330, BEEP},
  {1, 330, BEEP},
  {0,   0, BEEP},
  {1, 330, BEEP},
  {0,   0, BEEP},
  {1, 262, BEEP},
  {1, 330, BEEP},
  {0,   0, BEEP},
  {1, 392, BEEP},
  {0,   0, BEEP*3},
  {1, 196, BEEP*2},
  {1, 1975, 75},
  {1, 2637, 75},
  {0,   0, BEEP},
  {1, 523, BEEP},
  {0,   0, BEEP*2},
  {1, 392, BEEP},
  {0,   0, BEEP*2},
  {1, 330, BEEP},
  {0,   0, BEEP*2},
  {1, 440, BEEP},
  {0,   0, BEEP},
  {1, 494, BEEP},
  {0,   0, BEEP},
  {1, 466, BEEP},
  {1, 440, BEEP},
  {0,   0, BEEP},
  {1, 392, BEEP},
  {1, 659, BEEP},
  {0,   0, BEEP},
  {1, 784, BEEP},
  {1, 880, BEEP},
  {0,   0, BEEP},
  {1, 698, BEEP},
  {1, 784, BEEP},
  {0,   0, BEEP},
  {1, 659, BEEP},
  {0,   0, BEEP},
  {1, 523, BEEP},
  {1, 587, BEEP},
  {1, 494, 2*BEEP}
};

void setup(){

}

void loop(){
  if(notes[t].exist == 1){
    tone(speakerPin, notes[t].note, notes[t].time);
  }
  delay(notes[t].time);
  t++;
  if(t > 86-1)t = 0;
}
