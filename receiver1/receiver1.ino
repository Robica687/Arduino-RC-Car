#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int motorFataStangaInainte = 6;
const int motorFataStangaInapoi = 5;
const int motorFataDreaptaInainte = 4;
const int motorFataDreaptaInapoi = 3;

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

  pinMode(motorFataStangaInainte, OUTPUT);
  pinMode(motorFataStangaInapoi, OUTPUT);
  pinMode(motorFataDreaptaInainte, OUTPUT);
  pinMode(motorFataDreaptaInapoi, OUTPUT);
}

void loop() {

  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);

    if(strcmp(text, fata) == 0){
      digitalWrite(motorFataStangaInainte, LOW);
      digitalWrite(motorFataStangaInapoi, HIGH);
      digitalWrite(motorFataDreaptaInainte, LOW);
      digitalWrite(motorFataDreaptaInapoi, HIGH);
      delay(500);
    }

    if(strcmp(text, spate) == 0){
      digitalWrite(motorFataStangaInainte, HIGH);
      digitalWrite(motorFataStangaInapoi, LOW);
      digitalWrite(motorFataDreaptaInainte, HIGH);
      digitalWrite(motorFataDreaptaInapoi, LOW);
      delay(500);
    }

    if(strcmp(text, stanga) == 0){
      digitalWrite(motorFataStangaInainte, LOW);
      digitalWrite(motorFataStangaInapoi, HIGH);
      digitalWrite(motorFataDreaptaInainte, HIGH);
      digitalWrite(motorFataDreaptaInapoi, LOW);
      delay(500);
    }

    if(strcmp(text, dreapta) == 0){
      digitalWrite(motorFataStangaInainte, HIGH);
      digitalWrite(motorFataStangaInapoi, LOW);
      digitalWrite(motorFataDreaptaInainte, LOW);
      digitalWrite(motorFataDreaptaInapoi, HIGH);
      delay(500);
    }

    if(strcmp(text, fataStanga) == 0){
      digitalWrite(motorFataStangaInainte, LOW);
      digitalWrite(motorFataStangaInapoi, HIGH);
      digitalWrite(motorFataDreaptaInainte, LOW);
      digitalWrite(motorFataDreaptaInapoi, LOW);
      delay(500);
    }

    if(strcmp(text, fataDreapta) == 0){
      digitalWrite(motorFataStangaInainte, LOW);
      digitalWrite(motorFataStangaInapoi, LOW);
      digitalWrite(motorFataDreaptaInainte, LOW);
      digitalWrite(motorFataDreaptaInapoi, HIGH);
      delay(500);
    }

    if(strcmp(text, spateStanga) == 0){
      digitalWrite(motorFataStangaInainte, LOW);
      digitalWrite(motorFataStangaInapoi, LOW);
      digitalWrite(motorFataDreaptaInainte, HIGH);
      digitalWrite(motorFataDreaptaInapoi, LOW);
      delay(500);
    }

    if(strcmp(text, spateDreapta) == 0){
      digitalWrite(motorFataStangaInainte, HIGH);
      digitalWrite(motorFataStangaInapoi, LOW);
      digitalWrite(motorFataDreaptaInainte, LOW);
      digitalWrite(motorFataDreaptaInapoi, LOW);
      delay(500);
    }

    if(strcmp(text, rotireStanga) == 0){
      digitalWrite(motorFataStangaInainte, HIGH);
      digitalWrite(motorFataStangaInapoi, LOW);
      digitalWrite(motorFataDreaptaInainte, LOW);
      digitalWrite(motorFataDreaptaInapoi, HIGH);
      delay(500);
    }

    if(strcmp(text, rotireDreapta) == 0){
      digitalWrite(motorFataStangaInainte, LOW);
      digitalWrite(motorFataStangaInapoi, HIGH);
      digitalWrite(motorFataDreaptaInainte, HIGH);
      digitalWrite(motorFataDreaptaInapoi, LOW);
      delay(500);
    }

  }

  if (!radio.available()) {
    digitalWrite(motorFataStangaInainte, LOW);
    digitalWrite(motorFataStangaInapoi, LOW);
    digitalWrite(motorFataDreaptaInainte, LOW);
    digitalWrite(motorFataDreaptaInapoi, LOW);
  }

}
