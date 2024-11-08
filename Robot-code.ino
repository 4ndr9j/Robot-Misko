#include <Servo.h>

#define Led A3                      // Orange
#define LeftPositive 2              // Purple       IN1
#define LeftNegative 4              // Green        IN2
#define RightNegative 12            // White        IN3
#define RightPositive 13            // Orange       IN4
#define Trigger 7                   // Green
#define Echo 8                      // Blue

Servo Griper;        // 11  Purple
Servo Ploca;         // 10  Blue
Servo Treca_Ruka;    // 9   Green    
Servo Druga_Ruka;    // 6   Yellow
Servo Prva_Ruka;     // 5   Orange

#define RegulatedSpeed 3                  // Yellow to breadboard, purple to left, orange to right

void setup() {
  // Led
  pinMode(Led, OUTPUT);

  // Differential motors
  pinMode(LeftPositive, OUTPUT);
  pinMode(LeftNegative, OUTPUT);
  pinMode(RightNegative, OUTPUT);
  pinMode(RightPositive, OUTPUT);
  pinMode(RegulatedSpeed, OUTPUT);
  
  // Ultrasonic sensor
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);

  // Servo motors
  Prva_Ruka.attach(5);                 // Normalno na 90, + za spustanje, - za podizanje
  Druga_Ruka.attach(6);                // Normalno na 90, + za spustanje, - za podizanje
  Treca_Ruka.attach(9);                // Normalno na 82, + za podizanje, - za spustanje
  Ploca.attach(10);                    // Griper normalan na podlogu na 96, + za lijevo, - za desno
  Griper.attach(11);                   // Paralelni na 90, + za skupljanje(108 je najvece skupljanje), - za sirenje

  Serial.begin(9600);

}

void loop() {

  digitalWrite(Led, LOW);

  NeutralPosition();

  ClosingDistance(10);

}

// FUNCTIONS

// Color Sensor

    // Yet to be decided...

// Gripper

void NeutralPosition() {
  Griper.write(108);
  Ploca.write(96);
  Treca_Ruka.write(170);
  Druga_Ruka.write(135);
  Prva_Ruka.write(40);
}

void LiftingObject() {             // Waiting for ClosingDistance() to be tested

}

void DropingObject() {             // Waiting for LiftingObject() to be tested

}

// Movement

void ClosingDistance(float target) {
  float duration, distance;

  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  duration = pulseIn(Echo, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);

  while (target < distance) {

    digitalWrite(Trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(Trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trigger, LOW);

    duration = pulseIn(Echo, HIGH);
    distance = (duration*.0343)/2;
    Serial.print("Distance: ");
    Serial.println(distance);

    if (distance - target < 5) {
      Forward(90);
    } else if (distance - target >= 5 && distance - target <= 10) {
      Forward(127);
    } else {
      Forward(255);
    }

  }

  Stop();
  delay(500);

}

void Right90(int speed) {
  Right(speed);
  delay(250);          // Needs to be tested
  Stop();
}

void Left90(int speed) {
  Left(speed);
  delay(250);          // Needs to be tested
  Stop();
}


void Forward(int speed) {
  digitalWrite(LeftPositive, HIGH);
  digitalWrite(LeftNegative, LOW);
  digitalWrite(RightPositive, HIGH);
  digitalWrite(RightNegative, LOW);
  analogWrite(RegulatedSpeed, speed);
  
}

void Backward(int speed) {
  digitalWrite(LeftPositive, LOW);
  digitalWrite(LeftNegative, HIGH);
  digitalWrite(RightPositive, LOW);
  digitalWrite(RightNegative, HIGH);
  analogWrite(RegulatedSpeed, speed);
  
}

void Right(int speed) {
  digitalWrite(LeftPositive, HIGH);
  digitalWrite(LeftNegative, LOW);
  digitalWrite(RightPositive, LOW);
  digitalWrite(RightNegative, HIGH);
  analogWrite(RegulatedSpeed, speed);
  
}

void Left(int speed) {
  digitalWrite(LeftPositive, LOW);
  digitalWrite(LeftNegative, HIGH);
  digitalWrite(RightPositive, HIGH);
  digitalWrite(RightNegative, LOW);
  analogWrite(RegulatedSpeed, speed);
  
}

void Stop() {
  digitalWrite(LeftPositive, LOW);
  digitalWrite(LeftNegative, LOW);
  digitalWrite(RightPositive, LOW);
  digitalWrite(RightNegative, LOW);
}

