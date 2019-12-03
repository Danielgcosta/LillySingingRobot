#include "pitches.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define buzzerPin1 13
#define buzzerPin2 12
#define buzzerPin3 11
#define buzzerPin4 10
#define led1 2
#define led2 3
#define led3 4
#define led4 5

LiquidCrystal_I2C lcd(0x27,16,2); 

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
  lcd.init();
  lcd.backlight();
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

void lcdDisplayTempo(int i){
    if(i<interval/(64*timestep)){
    lcd.setCursor(12,1);
    lcd.print("1");
  }
  else if(i<interval/(48*timestep)){
    lcd.setCursor(12,1);
    lcd.print(" 2");
  }
  else if(i<interval/(32*timestep)){
    lcd.setCursor(12,1);
    lcd.print("  3");
  }
  else{
    lcd.setCursor(12,1);
    lcd.print("   4");
  }
}

void chord(int note1, int note2, int note3, int note4){
  lcd.setCursor(12,1);
  lcd.print("    ");
  ledsOff();
  digitalWrite(led1,HIGH);
  lcd.setCursor(0,1);
  lcd.print("1");
    
  for(int i=0; i<interval/(16*timestep); i++){
    squareNote(buzzerPin1, note1);
    squareNote(buzzerPin2, note2); 
    squareNote(buzzerPin3, note3);
    squareNote(buzzerPin4, note4);
    lcdDisplayTempo(i);
  }
  lcd.setCursor(12,1);
  lcd.print("    ");
  ledsOff();
  digitalWrite(led2,HIGH);
    lcd.setCursor(2,1);
    lcd.print("2");
  for(int i=0; i<interval/(16*timestep); i++){
    squareNote(buzzerPin1, note1);
    squareNote(buzzerPin2, note2); 
    squareNote(buzzerPin3, note3);
    squareNote(buzzerPin4, note4);
    lcdDisplayTempo(i);
  }
  lcd.setCursor(12,1);
  lcd.print("    ");
  ledsOff();
  digitalWrite(led3,HIGH); 
    lcd.setCursor(4,1);
    lcd.print("3");
  for(int i=0; i<interval/(16*timestep); i++){
    squareNote(buzzerPin1, note1);
    squareNote(buzzerPin2, note2); 
    squareNote(buzzerPin3, note3);
    squareNote(buzzerPin4, note4);
    lcdDisplayTempo(i);
    }
  lcd.setCursor(12,1);
  lcd.print("    ");
  ledsOff();
  digitalWrite(led4,HIGH);
    lcd.setCursor(6,1);
    lcd.print("4");
  for(int i=0; i<interval/(16*timestep); i++){
    squareNote(buzzerPin1, note1);
    squareNote(buzzerPin2, note2); 
    squareNote(buzzerPin3, note3);
    squareNote(buzzerPin4, note4);
    lcdDisplayTempo(i);
  }
}


void verse(){
  Serial.print("E/B");  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("E/B");
  chord(NOTE_E4,NOTE_GS4,NOTE_B4,NOTE_B3);
  Serial.print(" F#/C#");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("F#/C#");
  chord(NOTE_FS4,NOTE_AS4,NOTE_CS5,NOTE_CS4);
  Serial.print(" A/E");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A/E");
  chord(NOTE_A4,NOTE_CS5,NOTE_D5,NOTE_E4);
  Serial.println(" Am/E");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Am/E");
  chord(NOTE_A4,NOTE_C5,NOTE_D5,NOTE_E4);
}

void chorus(){
  Serial.print("A");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A");
  chord(NOTE_A4,NOTE_CS5,NOTE_E5,NOTE_A5);
  Serial.print(" F#m");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("F#m");
  chord(NOTE_FS4,NOTE_A4,NOTE_CS5,NOTE_FS6);
  Serial.print(" C#m");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("C#m");
  chord(NOTE_CS4,NOTE_E4,NOTE_GS5,NOTE_CS5);
  Serial.print(" G#m");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("G#m");
  chord(NOTE_GS4,NOTE_C5,NOTE_DS5,NOTE_CS4);
  Serial.print(" A");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A");
  chord(NOTE_A4,NOTE_CS5,NOTE_E5,NOTE_A5);
  Serial.print(" A9");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A9");
  chord(NOTE_A4,NOTE_B4,NOTE_E5,NOTE_A5);
  Serial.print(" E/B");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("E/B");
  chord(NOTE_E4,NOTE_GS4,NOTE_B4,NOTE_B5);
  Serial.println(" E7/B");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("E7/B");
  chord(NOTE_D4,NOTE_GS4,NOTE_B4,NOTE_E5);

  Serial.print("A");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A");
  chord(NOTE_A4,NOTE_CS5,NOTE_E5,NOTE_A5);
  Serial.print(" F#m");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("F#m");
  chord(NOTE_FS4,NOTE_A4,NOTE_CS5,NOTE_FS6);
  Serial.print(" C#m");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("C#m");
  chord(NOTE_CS4,NOTE_E4,NOTE_GS5,NOTE_CS5);
  Serial.print(" G#m");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("G#m");
  chord(NOTE_GS4,NOTE_C5,NOTE_DS5,NOTE_CS4);
  Serial.print(" A");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A");
  chord(NOTE_A4,NOTE_CS5,NOTE_E5,NOTE_A5);
  Serial.println(" A9");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A9");
  chord(NOTE_A4,NOTE_B4,NOTE_E5,NOTE_A5);
}

void outro(){
  Serial.print("F#m");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("F#m");
  chord(NOTE_FS4,NOTE_A4,NOTE_CS5,NOTE_FS6);
  Serial.print(" A");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A");
  chord(NOTE_A4,NOTE_CS5,NOTE_E5,NOTE_A5);
  Serial.print(" G#m");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("G#m");
  chord(NOTE_GS4,NOTE_C5,NOTE_DS5,NOTE_CS4);
  Serial.print(" C#m");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("C#m");
  chord(NOTE_CS4,NOTE_E4,NOTE_GS5,NOTE_CS5);
  Serial.print(" A");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A");
  chord(NOTE_A4,NOTE_CS5,NOTE_E5,NOTE_A5);
  Serial.print(" A9");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A9");
  chord(NOTE_A4,NOTE_B4,NOTE_E5,NOTE_A5);
  Serial.print(" E/B");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("E/B");
  chord(NOTE_E4,NOTE_GS4,NOTE_B4,NOTE_B5);
  Serial.println(" E7/B");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("E7/B");
  chord(NOTE_D4,NOTE_GS4,NOTE_B4,NOTE_E5);  
}

void lastVerse(){
  Serial.print("E/B");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("E/B");
  chord(NOTE_E4,NOTE_GS4,NOTE_B4,NOTE_B3);
  Serial.print(" F#/C#");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("F#/C#");
  chord(NOTE_FS4,NOTE_AS4,NOTE_CS5,NOTE_CS4);
  Serial.print(" A/E");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A/E");
  chord(NOTE_A4,NOTE_CS5,NOTE_D5,NOTE_E4);
  int backup = interval;
  interval =  interval/4;
  Serial.println(" Am/E");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Am/E");
  chord(NOTE_A4,NOTE_C5,NOTE_D5,NOTE_E4);
  delay(backup-interval);
  interval = backup;
}

void playSong(){
  lcd.clear();
  lcd.print("Song: ");
  lcd.print("Ai, amor");
  lcd.setCursor(0,1);
  lcd.print("by AnaVitoria");
  delay(2000);
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
