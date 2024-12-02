#include <Servo.h>

#define LeftPositive 2              // Purple       IN1
#define LeftNegative 4              // Green        IN2
#define RightNegative 12            // White        IN3
#define RightPositive 13            // Orange       IN4
#define Trigger 7                   // Green
#define Echo 8                      // Blue

#define LeftIRSensor A1
#define RightIRSensor A0

Servo Griper;        // 11  Purple
Servo Ploca;         // 10  Blue
Servo Treca_Ruka;    // 9   Green    
Servo Druga_Ruka;    // 6   Yellow
Servo Prva_Ruka;     // 5   Orange

#define RegulatedSpeed 3                  // Orange to breadboard, Purple to left, Blue to right

int n = 0;             // Used to determine how many times both IR sensors have been on black at the same time

void setup() {

  // IR Sensors
  pinMode(LeftIRSensor, INPUT);
  pinMode(RightIRSensor, INPUT);

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

  NeutralPosition();

  
  bool LeftIR = digitalRead(LeftIRSensor);         // White == 0, Black == 1;
  bool RightIR = digitalRead(RightIRSensor);

  if (LeftIR == 1 && RightIR == 1) {          // Assuming that 1 is value given on white, 0 on black. (Needs to be checked)
    Stop();
  } else if (LeftIR == 0 && RightIR == 1) {
    Right(120);
  } else if (LeftIR == 1 && RightIR == 0) {
    Left(120);
  } else if (LeftIR == 0 && RightIR == 0) {   // Both on black, needs to check n (*no of both sensors on black)
    Forward(255);
  }

  
}

// FUNCTIONS

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

