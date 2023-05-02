// Declarando Constantes Globales
const int sensorPin = A0; //Asignando Clavija A0 a sensorPin
const float baselineTemp = 20.0; // Asignando Temperatura Hambiente

void setup () {
  Serial.begin(9600); // Inicializando Puerto Serial
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) { // Inicializando clavijas de LEDs
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
} 

void loop () {
  int sensorVal = analogRead(sensorPin); // Tomamos la lectura de la clavija A0 y la almacenamos en la variable entero sensorVal
  Serial.print("Valor del sensor: ");
  Serial.print(sensorVal); // Imprimimos su valor que va de 0 a 1023

  float voltage = (sensorVal / 1024.0) * 5.0; // Convertimos la lectura del sensor en voltaje y lo almacenamos en la variable flotante voltage
  Serial.print(" , Voltaje: ");
  Serial.print(voltage);
  Serial.print(" Volts"); // Imprimimos su valor que va de 0 a 5v

  float temperature = (voltage - 0.5) * 100; // Convertimos el valor de voltaje a temperatura y lo almacenamos en la variable flotante temperatura
  Serial.print(" , Temperatura: ");
  Serial.print(temperature);
  Serial.println(" ºC"); // Imprimimos su valor, con un salto de línea

  if (temperature < baselineTemp) { // Si la temperatura es menor a la temperatura hambiente apagamos todos los LEDs
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) { // Si la temperatura es superior a la temperatura hambiente + 2, e inferior a la temperatura hambiente + 4 se enciende un LED
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  delay(1000);
}