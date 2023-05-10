#include <Servo.h>
Servo myServo;

const int potPin = A0;
int potVal = 0;
int angulo = 0;

void setup () {
  myServo.attach(9);
  Serial.begin(9600);
}

void loop () {
  potVal = analogRead(potPin);
  Serial.print("Valor del Potenciometro: ");
  Serial.print(potVal);

  angulo = map(potVal, 0, 1023, 0, 179);
  Serial.print(" || Angulo: ");
  Serial.println(angulo);

  myServo.write(angulo);
  delay(15);
}