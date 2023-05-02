int switchState = 0;
void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  switchState = digitalRead(2);
  if(switchState == LOW) {
    // El boton no está pulsado
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
else { // El boton está pulsado
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(250); // espera un cuarto de segundo
    // permuta los LEDs
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250); // espera un cuarto de segundo
  }
} // vuelve al inicio del bucle