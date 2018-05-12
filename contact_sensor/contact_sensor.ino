//using interrupts is unreliable, just use normal digitalRead if statement
//pins 2 or 3 alone can be used for interrupts (for the Uno)

#include <Servo.h>
Servo myservo;

int pos = 0;
bool contactMade = false;
const int contactPin = 3; 

void setup() {
  Serial.begin(9600);
  pinMode(contactPin,INPUT);
  myservo.attach(9);
  myservo.write(pos);
}

void loop() {
   contactMade = digitalRead(contactPin);
    if(contactMade) {
      Serial.println("On");
      // move linear actuator in
      while(pos>0) { 
        pos--;
        myservo.write(pos);
        Serial.println(pos);              
        delay(15);                       
      }
    } else {
      Serial.println("Off");
      // move linear actuator back out
      while(pos<180) { 
        pos++;
        myservo.write(pos); 
        Serial.println("else");
        Serial.println(pos);            
        delay(15);                   
      }
    }
}

