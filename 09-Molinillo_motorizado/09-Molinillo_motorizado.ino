// Declarando constantes para clavijas del pulsador y el motor
const int switchPin = 2;
const int motorPin = 9;
// Declarando variable para almacenar el estado del pulsador
int switchState = 0;

void setup() {
// Configurando clavija del pulsador como entrada, y del motor como salida
  pinMode(switchPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
// Leyendo clavija del pulsador y almacenando en variable
  switchState = digitalRead(switchPin);

  if (switchState == HIGH) {
    digitalWrite(motorPin, HIGH);
  }
  else {
    digitalWrite(motorPin, LOW);
  }
}