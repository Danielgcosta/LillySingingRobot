#include "pitches.h"
#define buzzerPin1 13
#define buzzerPin2 12
#define buzzerPin3 11
#define buzzerPin4 10
#define led1 2
#define led2 3
#define led3 4
#define led4 5

int interval = 2300;
int timestep = 20;
  
void setup(){
  Serial.begin(9600);
  pinMode(buzzerPin1,OUTPUT);
  pinMode(buzzerPin2,OUTPUT);
  pinMode(buzzerPin3,OUTPUT);
  pinMode(buzzerPin4,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
}

void squareNote(int buzzerPin, int note){
  tone(buzzerPin, note);
  delay(timestep);
  noTone(buzzerPin);
}

void ledsOff(){
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
}

void chord(int note1, int note2, int note3, int note4){
  ledsOff();
  digitalWrite(led1,HIGH);
  for(int i=0; i<interval/(16*timestep); i++){
    squareNote(buzzerPin1, note1);
    squareNote(buzzerPin2, note2); 
    squareNote(buzzerPin3, note3);
    squareNote(buzzerPin4, note4);
  }
  ledsOff();
  digitalWrite(led2,HIGH);
  for(int i=0; i<interval/(16*timestep); i++){
    squareNote(buzzerPin1, note1);
    squareNote(buzzerPin2, note2); 
    squareNote(buzzerPin3, note3);
    squareNote(buzzerPin4, note4);
  }
  ledsOff();
  digitalWrite(led3,HIGH); 
  for(int i=0; i<interval/(16*timestep); i++){
    squareNote(buzzerPin1, note1);
    squareNote(buzzerPin2, note2); 
    squareNote(buzzerPin3, note3);
    squareNote(buzzerPin4, note4);
  }
  ledsOff();
  digitalWrite(led4,HIGH);
  for(int i=0; i<interval/(16*timestep); i++){
    squareNote(buzzerPin1, note1);
    squareNote(buzzerPin2, note2); 
    squareNote(buzzerPin3, note3);
    squareNote(buzzerPin4, note4);
  }
}


void verse(){
  Serial.print("E/B");
  chord(NOTE_E4,NOTE_GS4,NOTE_B4,NOTE_B3);
  Serial.print(" F#/C#");
  chord(NOTE_FS4,NOTE_AS4,NOTE_CS5,NOTE_CS4);
  Serial.print(" A/E");
  chord(NOTE_A4,NOTE_CS5,NOTE_D5,NOTE_E4);
  Serial.println(" Am/E");
  chord(NOTE_A4,NOTE_C5,NOTE_D5,NOTE_E4);
}

void chorus(){
  Serial.print("A");
  chord(NOTE_A4,NOTE_CS5,NOTE_E5,NOTE_A5);
  Serial.print(" F#m");
  chord(NOTE_FS4,NOTE_A4,NOTE_CS5,NOTE_FS6);
  Serial.print(" C#m");
  chord(NOTE_CS4,NOTE_E4,NOTE_GS5,NOTE_CS5);
  Serial.print(" G#m");
  chord(NOTE_GS4,NOTE_C5,NOTE_DS5,NOTE_CS4);
  Serial.print(" A");
  chord(NOTE_A4,NOTE_CS5,NOTE_E5,NOTE_A5);
  Serial.print(" A9");
  chord(NOTE_A4,NOTE_B4,NOTE_E5,NOTE_A5);
  Serial.print(" E/B");
  chord(NOTE_E4,NOTE_GS4,NOTE_B4,NOTE_B5);
  Serial.println(" E7/B");
  chord(NOTE_D4,NOTE_GS4,NOTE_B4,NOTE_E5);

  Serial.print("A");
  chord(NOTE_A4,NOTE_CS5,NOTE_E5,NOTE_A5);
  Serial.print(" F#m");
  chord(NOTE_FS4,NOTE_A4,NOTE_CS5,NOTE_FS6);
  Serial.print(" C#m");
  chord(NOTE_CS4,NOTE_E4,NOTE_GS5,NOTE_CS5);
  Serial.print(" G#m");
  chord(NOTE_GS4,NOTE_C5,NOTE_DS5,NOTE_CS4);
  Serial.print(" A");
  chord(NOTE_A4,NOTE_CS5,NOTE_E5,NOTE_A5);
  Serial.println(" A9");
  chord(NOTE_A4,NOTE_B4,NOTE_E5,NOTE_A5);
}

void outro(){
  Serial.print("F#m");
  chord(NOTE_FS4,NOTE_A4,NOTE_CS5,NOTE_FS6);
  Serial.print(" A");
  chord(NOTE_A4,NOTE_CS5,NOTE_E5,NOTE_A5);
  Serial.print(" G#m");
  chord(NOTE_GS4,NOTE_C5,NOTE_DS5,NOTE_CS4);
  Serial.print(" C#m");
  chord(NOTE_CS4,NOTE_E4,NOTE_GS5,NOTE_CS5);
  Serial.print(" A");
  chord(NOTE_A4,NOTE_CS5,NOTE_E5,NOTE_A5);
  Serial.print(" A9");
  chord(NOTE_A4,NOTE_B4,NOTE_E5,NOTE_A5);
  Serial.print(" E/B");
  chord(NOTE_E4,NOTE_GS4,NOTE_B4,NOTE_B5);
  Serial.println(" E7/B");
  chord(NOTE_D4,NOTE_GS4,NOTE_B4,NOTE_E5);  
}

void lastVerse(){
  Serial.print("E/B");
  chord(NOTE_E4,NOTE_GS4,NOTE_B4,NOTE_B3);
  Serial.print(" F#/C#");
  chord(NOTE_FS4,NOTE_AS4,NOTE_CS5,NOTE_CS4);
  Serial.print(" A/E");
  chord(NOTE_A4,NOTE_CS5,NOTE_D5,NOTE_E4);
  int backup = interval;
  interval =  interval/4;
  Serial.println(" Am/E");
  chord(NOTE_A4,NOTE_C5,NOTE_D5,NOTE_E4);
  delay(backup-interval);
  interval = backup;
}

void playSong(){
  verse();
  verse();
  verse();
  verse();  

  chorus();

  verse();
  lastVerse();
  verse();

  chorus();

  outro();
  outro();

  chorus();
  
  verse();
  lastVerse();
  delay(1000000);
}


void loop(){
  playSong();
}
