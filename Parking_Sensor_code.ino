// Definirea pinilor pentru senzorul HC-SR04
const int trigPin = 16; // D16 pe ESP32 sau D7 pe Arduino Nano
const int echoPin = 13; // D13 pe ESP32 sau D6 pe Arduino Nano
// Definirea pinului pentru LED
const int red = 27;
const int yellow = 14;
const int green = 12;
const int buzz = 22;
long duration;
int distance;
void setup() {
// Inițializarea pinilor
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(red, OUTPUT);
pinMode(yellow, OUTPUT);
pinMode(green, OUTPUT);
pinMode(buzz, OUTPUT);
// Inițializarea serial pentru debug
Serial.begin(9600);
}
void loop() {
// Trimiterea semnalului de trigger către senzor HC-SR04
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Citirea duratei pulsului de la senzor (în microsecunde)

duration = pulseIn(echoPin, HIGH);
// Calcularea distanței în centimetri
distance = duration * 0.034 / 2;
// Afisarea distanței în Serial Monitor
Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");
// Verificarea distanței și controlul LED-ului
if (distance > 30)
{
digitalWrite(green, HIGH); // Aprindere LED verde
digitalWrite(yellow, LOW); 
digitalWrite(red, LOW);
digitalWrite(buzz, LOW); 
}
else if (distance >10)
{
digitalWrite(green, LOW); 
digitalWrite(yellow, HIGH); // Aprindere LED galben
digitalWrite(red, LOW);
digitalWrite(buzz, LOW); 
}
else 
{
digitalWrite(green, LOW); 
digitalWrite(yellow, LOW); 
digitalWrite(red, HIGH); // Aprindere LED rosu
digitalWrite(buzz, HIGH); // Semnal buzzer
}
// Așteptare pentru următoarea măsurătoare
delay(100);
}
