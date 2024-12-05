#define RightSpeed 5         //  Purple
#define LeftSpeed 6          //  Blue
#define RightPositive 8      //  Green
#define RightNegative 9      //  Blue
#define LeftNegative 10      //  White
#define LeftPositive 11      //  Orange

void setup() {
  pinMode(RightSpeed, OUTPUT);
  pinMode(LeftSpeed, OUTPUT);
  pinMode(RightPositive, OUTPUT);
  pinMode(RightNegative, OUTPUT);
  pinMode(LeftNegative, OUTPUT);
  pinMode(LeftPositive, OUTPUT);

}

void loop() {  // Working

  Forward(255);

  delay(2500);

  Stop();

  delay(2000);

  Arch(255, 100);

  delay(2000); //1700

  Stop();
  delay (2000);

  Right(255);

  delay(850);

  Stop();

  delay(3000);
  
  Forward(255);
  delay(10000);

  Stop();
  delay(10000);

}

void Arch(int LSpeed, int RSpeed) {
  digitalWrite(RightPositive, HIGH);
  digitalWrite(RightNegative, LOW);
  digitalWrite(LeftPositive, HIGH);
  digitalWrite(LeftNegative, LOW);
  analogWrite(LeftSpeed, LSpeed);
  analogWrite(RightSpeed, RSpeed);

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
