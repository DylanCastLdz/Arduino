const int controlPinL = 2;
const int controlPinR = 3;
const int velPin = 9;
const int directionSwitchPin = 4;
const int powerPin = 5;
const int potPin = A0;

int powerState = 0;
int previousPowerState = 0;
int directionState = 0;
int previousDirectionState = 0;

int motorEnable = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  pinMode(directionSwitchPin, INPUT);
  pinMode(powerPin, INPUT);
  pinMode(controlPinL, OUTPUT);
  pinMode(controlPinR, OUTPUT);
  pinMode(powerPin, OUTPUT);

  digitalWrite(velPin, LOW);
}

void loop() {
  powerState = digitalRead(powerPin);
  delay(1);

  directionState = digitalRead(directionSwitchPin);

  motorSpeed = analogRead(potPin)/4;

  if (powerState != previousPowerState) {
    if (powerState == HIGH) {
      motorEnable =! motorEnable;
    }
  }

  if (directionState != previousDirectionState) {
    if (directionState == HIGH) {
      motorDirection =! motorDirection;
    }
  }

  if (motorDirection == 1) {
    digitalWrite(controlPinL, HIGH);
    digitalWrite(controlPinR, LOW);
  }
  else {
    digitalWrite(controlPinL, LOW);
    digitalWrite(controlPinR, HIGH);
  }

  if (motorEnable == 1) {
    analogWrite(velPin, motorSpeed);
  }
  else {
    analogWrite(velPin, 0);
  }

  previousDirectionState = directionState;
  previousPowerState = powerState;
}