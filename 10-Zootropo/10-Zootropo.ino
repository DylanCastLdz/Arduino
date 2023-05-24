// Declarando constantes para clavijas
// unoA y dosA controlan la dirección del giro
const int unoA = 2;
const int dosA = 3;
const int en1 = 9;  // enciende y apaga el motor, así como suministra PWM al L293D
const int inverterPuls = 4;  // recibe la señal del pulsador de cambio de dirección
const int powerPuls = 5;  // recibe la señal del pulsador de encendido y apagado
const int potPin = A0;  // recibe la señal del potenciometro de giro

int powerState = 0;  // para almacenar el estado del pulsador de power
int previousPowerState = 0;  // para almacenar una copia del estado actual del pulsador antes de actualizarlo

int directionState = 0;  // para almacenat el sentido actual de giro
int previousDirectionState = 0;  // para almacenar una copia del sentido actual de giro antes de actualizarlo

int motorSpeed = 0;  // para registrar la velocidad
int motorEnable = 0;  // para controlar el encendido y apagado
int motorDirection = 1;  // para registrar en qué dirección gira el motor

void setup() {
  pinMode(unoA, OUTPUT);
  pinMode(dosA, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(inverterPuls, INPUT);
  pinMode(powerPuls, INPUT);

  digitalWrite(en1, LOW);
}

void loop() {
  powerState = digitalRead(powerPuls);
  delay(1);
  directionState = digitalRead(inverterPuls);
  motorSpeed = analogRead(potPin)/4;

  if (powerState != previousPowerState) {
    if (powerState == HIGH) {
      motorEnable = !motorEnable;
    }
  }

  if (directionState != previousDirectionState) {
    if (directionState == HIGH) {
      motorDirection = !motorDirection;
    }
  }

  if (motorDirection == 1) {
    digitalWrite(unoA, HIGH);
    digitalWrite(dosA, LOW);
  }
  else {
    digitalWrite(unoA, LOW);
    digitalWrite(dosA, HIGH);
  }

  if (motorEnable == 1) {
    analogWrite(en1, motorSpeed);
  }
  else {
    analogWrite(en1, 0);
  }

  previousDirectionState = directionState;
  previousPowerState = powerState;
}