int sensorValue; // Almacena el valor de la resistencia LDR
int sensorLow = 1023;  // Almacena el valor mapeado del sensor
int sensorHigh = 0;  // Almacena el valor mapeado del sensor

const int ledPin = 13;  // Se define clavija del indicador luminoso para la calibración

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);  // Se enciende indicador luminoso

// El siguiente bucle calibrará el sensor y convertirá sus valores maximos y minimos en un rango que el piezo pueda usar
  while(millis() < 5000) {
    sensorValue = analogRead(A0);  // Se lee la clavija A0 para recibir la señal de la resistencia LDR (Sensor)
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue; 
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }

  digitalWrite(ledPin, LOW);  // Se apaga el indicador luminoso luego de la calibración
}

void loop() {
  sensorValue = analogRead(A0);  // Se lee la clavija A0 para recibir la señal del sensor

  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);  // Se mapea el valor del sensor a un rango usable por el piezo y lo guardamos en la variable "pitch"


// Se imprime en el monitor serial el valor de entrada y de salida
  Serial.print("sensorValue: ");
  Serial.print(sensorValue);
  Serial.print(" || Pitch: ");
  Serial.println(pitch);

// Se envía la señal al piezo para producir sonido
  tone(8, pitch, 20);
  delay(10);
}
