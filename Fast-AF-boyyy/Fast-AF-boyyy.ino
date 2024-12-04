#define RightSpeed 5
#define LeftSpeed 6
#define RightPositive 8
#define RightNegative 9
#define LeftNegative 10
#define LeftPositive 11 

void setup() {
  pinMode(RightSpeed, OUTPUT);
  pinMode(LeftSpeed, OUTPUT);
  pinMode(RightPositive, OUTPUT);
  pinMode(RightNegative, OUTPUT);
  pinMode(LeftNegative, OUTPUT);
  pinMode(LeftPositive, OUTPUT);

}

void loop() {  // Untested, just a sketch
  
  Forward(200);

  delay(1000);

  RightOne(130);

  delay(350);

  Forward(150);

  delay(1000);

  RightOne(130);
  
  delay(350);

  Forward(200);

  delay(2500);

  Stop();

  delay(1000);

  Backward(150);

  delay(750);

  Stop();

  delay(1000);

}


void Forward(int speed) {
  digitalWrite(RightPositive, HIGH);
  digitalWrite(RightNegative, LOW);
  digitalWrite(LeftPositive, HIGH);
  digitalWrite(LeftNegative, LOW);
  analogWrite(RightSpeed, speed);
  analogWrite(LeftSpeed, speed);

}

void Backward(int speed) {
  digitalWrite(RightPositive, LOW);
  digitalWrite(RightNegative, HIGH);
  digitalWrite(LeftPositive, LOW);
  digitalWrite(LeftNegative, HIGH);
  analogWrite(RightSpeed, speed);
  analogWrite(LeftSpeed, speed);

}

void Left(int speed) {
  digitalWrite(RightPositive, HIGH);
  digitalWrite(RightNegative, LOW);
  digitalWrite(LeftPositive, LOW);
  digitalWrite(LeftNegative, HIGH);
  analogWrite(RightSpeed, speed);
  analogWrite(LeftSpeed, speed);

}

void LeftOne(int speed) {
  digitalWrite(RightPositive, HIGH);
  digitalWrite(RightNegative, LOW);
  digitalWrite(LeftPositive, LOW);
  digitalWrite(LeftNegative, LOW);
  analogWrite(RightSpeed, speed);

}

void Right(int speed) {
  digitalWrite(RightPositive, LOW);
  digitalWrite(RightNegative, HIGH);
  digitalWrite(LeftPositive, HIGH);
  digitalWrite(LeftNegative, LOW);
  analogWrite(RightSpeed, speed);
  analogWrite(LeftSpeed, speed);

}

void RightOne(int speed) {
  digitalWrite(RightPositive, LOW);
  digitalWrite(RightNegative, LOW);
  digitalWrite(LeftPositive, HIGH);
  digitalWrite(LeftNegative, LOW);
  analogWrite(LeftSpeed, speed);

}

void Stop() {
  digitalWrite(RightPositive, LOW);
  digitalWrite(RightNegative, LOW);
  digitalWrite(LeftPositive, LOW);
  digitalWrite(LeftNegative, LOW);
  
}
