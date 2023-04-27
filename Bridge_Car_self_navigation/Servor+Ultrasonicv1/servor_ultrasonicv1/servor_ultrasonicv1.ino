// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 12; 
// Create a servo object 

//Ultra sonic sensor'
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

Servo Servo1; 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin);
//Ultra sonic setup
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600);
}
void loop(){ 
  Serial.println("Distance");
Serial.println(ultrasonic_distance());
   // Make servo go to 0 degrees 
   Servo1.write(90); 
   delay(3000); 
   // Make servo go to 90 degrees 
   Servo1.write(0); 
   delay(2000); 
    //Make servo go to 180 degrees 
   Servo1.write(180); 
delay(1000); 
}


// Functions
int ultrasonic_distance(){

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  
  return distance;
}