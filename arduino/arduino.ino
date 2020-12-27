//add servo library
#include <Servo.h>

//define our servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

//define our potentiometers
int pot1 = A0;
int pot2 = A1;
int pot3 = A2;
int pot4 = A3;

//variable to read the values from the analog pin (potentiometers)
int valPot1;
int valPot2;
int valPot3;
int valPot4;

void setup()
{
  //attaches our servos on pins PWM 11-10-9-6 to the servos
  servo1.attach(11);
  servo2.attach(10);
  servo3.attach(9);
  servo4.attach(6);
  while (!Serial) {
    delay(5);
  }
  Serial.begin(9600);
}

void loop()
{
  //reads the value of potentiometers (value between 0 and 1023)
if(Serial.available()) {
  valPot1 = Serial.parseInt(SKIP_WHITESPACE);
  if(valPot1!=0) {
  valPot1 = map (valPot1, 1, 1024, 0, 180);   //scale it to use it with the servo (value between 0 and 180)
  servo1.write(valPot1);                      //set the servo position according to the scaled value
  }
  delay(5);
}
  
  valPot2 = analogRead(pot2);
  valPot2 = map (valPot2, 0, 1023, 0, 90);
  servo2.write(valPot2);
  delay(5);

  valPot3 = analogRead(pot3);
  valPot3 = map (valPot3, 0, 1023, 90, 180);
  servo3.write(valPot3);
  delay(5);

  valPot4 = analogRead(pot4);
  valPot4 = map (valPot4, 0, 1023, 0, 150);
  servo4.write(valPot4);
  delay(5);
}
