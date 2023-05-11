#include <Servo.h> // Incluyendo la libreria Servo.H
Servo myServo; // Creando el objetos "MyServo"

const int potPin = A0; // Asignando entrada analogica
int potVal = 0; // Variable para almacenar el valor del potenciometro
int angulo = 0; // Variable para almacenar el valor del ángulo

void setup () {
	myServo.attach(9); //Asignando salida del objeto "MyServo"
	Serial.begin(9600); //Inicializando puerto serial
}

void loop () {
	potVal = analogRead(potPin); //Leyendo potenciometro y almacenado en variable
	// Imprimiendo valores del potenciometro
	Serial.print("Valor del Potenciometro: "); 
	Serial.print(potVal);

	angulo = map(potVal, 0, 1023, 0, 179); // Convirtiendo valores del potenciometro a angulo válido para servo
	// Imprimiendo valores del angulo del servo
	Serial.print(" || Angulo: ");
	Serial.println(angulo);
  delay(500);

	// Enviando señal de movimiento al servo
	myServo.write(angulo);
	delay(15);
}