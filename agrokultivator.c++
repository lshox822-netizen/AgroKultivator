char data;
#include <Servo.h>

Servo myServo; 
int led=7;
int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11; // 12 dan 11 ga o'zgartirildi

void setup() {
   myServo.attach(4); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode (led,OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  if (Serial.available()) {
    data = Serial.read();

    // Oldinga
    if (data == 'F') {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
      digitalWrite(led,HIGH);
    }
    // Orqaga
    if (data == 'B') {
       digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
    }
    // Chapga (O'ng g'ildiraklar aylanadi, chapdagilar to'xtaydi)
    if (data == 'L') {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
    }
    // O'ngga (Chap g'ildiraklar aylanadi, o'ngdagilar to'xtaydi)
    if (data == 'R') {
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
    }
    if (data == 'Z') {
       myServo.write(0);
    }
     if (data == 'Y') {
       myServo.write(120);
    }
    // To'xtash
    if (data == 'S') {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led,LOW);
    }
  }
}
