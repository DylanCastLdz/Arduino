// Definiendo Variables y constantes globales
const int switchPin = 8; // se define la clavija de entrada

unsigned long previousTime = 0;  //  variable de tipo long sin signo para almacenar el tiempo previo
long interval = 1000;  // variable de control de tipo long para ingresar el intervalo de tiempo deseado en ms

int switchState = 0;  // variable para almacenar el estado actual del sensor
int prevSwitchState = 0;  // variable para almacenar el estado previo del sensor
int led = 2;  // variable de control para permutar con las clavijas de los leds inicializada en 2

void setup () {
  // se definen las clavijas del 2 al 7 como salidas
  for (int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }
  pinMode(switchPin, INPUT);  // se define la clavija 8 como entrada haciendo uso de la constatne
}

void loop () {
  // una variable local de tipo long sin signo almacena el tiempo actual en marcha
  unsigned long currentTime = millis();

  if (currentTime - previousTime > interval) {  // si el tiempo actual - el tiempo previo es mayor que el intervalo ...
    // ... 
    // 1. se iguala el tiempo previo con el tiempo actual
    // 2. se enciende el led con el valor actual de la variable de control "led"
    // 3. se incrementa el valor de la variable de control "led" en 1
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;
  }

  if (led == 7) {
    // ¿Que hacer si se cumple la hora?
  }

  switchState = digitalRead(switchPin);  // lee el pin del sensor y lo almacena en la variable "switchState"

  if (switchState != prevSwitchState) {  // si el estado actual del sensor es diferente al estado previo ...
    // ... se inicia un ciclo for que apaga todos los pines del 2 al 7
    for (int x = 2; x < 8; x++) {
      digitalWrite(x, LOW);
    }

    led = 2; // Se actualiza la variable de control "led" para que coincida con la clavija 2
    previousTime = currentTime; // se iguala el tiempo previo con el tiempo actual
  }

  prevSwitchState = switchState;
}