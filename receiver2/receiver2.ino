#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int motorSpateStangaInainte = 6;
const int motorSpateStangaInapoi = 5;
const int motorSpateDreaptaInainte = 4;
const int motorSpateDreaptaInapoi = 3;

const char fata[] = "fata";
const char spate[] = "spate";
const char stanga[] = "stanga";
const char dreapta[] = "dreapta";
const char fataStanga[] = "fata stanga";
const char fataDreapta[] = "fata dreapta";
const char spateStanga[] = "spate stanga";
const char spateDreapta[] = "spate dreapta";
const char rotireStanga[] = "rotire stanga";
const char rotireDreapta[] = "rotire dreapta"; 

RF24 radio(9, 8); // CE, CSN
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  pinMode(motorSpateStangaInainte, OUTPUT);
  pinMode(motorSpateStangaInapoi, OUTPUT);
  pinMode(motorSpateDreaptaInainte, OUTPUT);
  pinMode(motorSpateDreaptaInapoi, OUTPUT);
}

void loop() {

  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);

    if(strcmp(text, fata) == 0){
      digitalWrite(motorSpateStangaInainte, LOW);
      digitalWrite(motorSpateStangaInapoi, HIGH);
      digitalWrite(motorSpateDreaptaInainte, LOW);
      digitalWrite(motorSpateDreaptaInapoi, HIGH);
      delay(500);
    }

    if(strcmp(text, spate) == 0){
      digitalWrite(motorSpateStangaInainte, HIGH);
      digitalWrite(motorSpateStangaInapoi, LOW);
      digitalWrite(motorSpateDreaptaInainte, HIGH);
      digitalWrite(motorSpateDreaptaInapoi, LOW);
      delay(500);
    }

    if(strcmp(text, stanga) == 0){
      digitalWrite(motorSpateStangaInainte, LOW);
      digitalWrite(motorSpateStangaInapoi, HIGH);
      digitalWrite(motorSpateDreaptaInainte, HIGH);
      digitalWrite(motorSpateDreaptaInapoi, LOW);
      delay(500);
    }

    if(strcmp(text, dreapta) == 0){
      digitalWrite(motorSpateStangaInainte, HIGH);
      digitalWrite(motorSpateStangaInapoi, LOW);
      digitalWrite(motorSpateDreaptaInainte, LOW);
      digitalWrite(motorSpateDreaptaInapoi, HIGH);
      delay(500);
    }

    if(strcmp(text, fataStanga) == 0){
      digitalWrite(motorSpateStangaInainte, LOW);
      digitalWrite(motorSpateStangaInapoi, HIGH);
      digitalWrite(motorSpateDreaptaInainte, LOW);
      digitalWrite(motorSpateDreaptaInapoi, LOW);
      delay(500);
    }

    if(strcmp(text, fataDreapta) == 0){
      digitalWrite(motorSpateStangaInainte, LOW);
      digitalWrite(motorSpateStangaInapoi, LOW);
      digitalWrite(motorSpateDreaptaInainte, LOW);
      digitalWrite(motorSpateDreaptaInapoi, HIGH);
      delay(500);
    }

    if(strcmp(text, spateStanga) == 0){
      digitalWrite(motorSpateStangaInainte, LOW);
      digitalWrite(motorSpateStangaInapoi, LOW);
      digitalWrite(motorSpateDreaptaInainte, HIGH);
      digitalWrite(motorSpateDreaptaInapoi, LOW);
      delay(500);
    }

    if(strcmp(text, spateDreapta) == 0){
      digitalWrite(motorSpateStangaInainte, HIGH);
      digitalWrite(motorSpateStangaInapoi, LOW);
      digitalWrite(motorSpateDreaptaInainte, LOW);
      digitalWrite(motorSpateDreaptaInapoi, LOW);
      delay(500);
    }

    if(strcmp(text, rotireStanga) == 0){
      digitalWrite(motorSpateStangaInainte, LOW);
      digitalWrite(motorSpateStangaInapoi, HIGH);
      digitalWrite(motorSpateDreaptaInainte, HIGH);
      digitalWrite(motorSpateDreaptaInapoi, LOW);
      delay(500);
    }

    if(strcmp(text, rotireDreapta) == 0){
      digitalWrite(motorSpateStangaInainte, HIGH);
      digitalWrite(motorSpateStangaInapoi, LOW);
      digitalWrite(motorSpateDreaptaInainte, LOW);
      digitalWrite(motorSpateDreaptaInapoi, HIGH);
      delay(500);
    }

  }

  if (!radio.available()) {
    digitalWrite(motorSpateStangaInainte, LOW);
    digitalWrite(motorSpateStangaInapoi, LOW);
    digitalWrite(motorSpateDreaptaInainte, LOW);
    digitalWrite(motorSpateDreaptaInapoi, LOW);
  }
  
}
