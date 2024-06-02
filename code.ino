#define echoPin1 2
#define trigPin1 3
#define echoPin2 5
#define trigPin2 4
#include <Servo.h>//library
int* checkDistance();
void openGate(int gateno, long instant);
void closeGate(int gateno, long instant);
Servo servo1, servo2;
int servoPin1 = 9;
int servoPin2 = 10;
static unsigned long myTime1, myTime2;
int distance[2];
int check1, check2;

void setup()
{pinMode(13, OUTPUT);//servo2 indicator
  pinMode(12, OUTPUT);//servo1 indicator
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  servo1.attach(servoPin1);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  servo2.attach(servoPin2);
  Serial.begin(9600);
  servo1.write(180);
  servo2.write(0);
  delay(1000);
}

void loop() {
  int *ptr;
  ptr = checkDistance();

  if (check1 == 0) {
    if (*ptr < 20) {
      myTime1 = millis();
      check1 = 1;
       digitalWrite(12,1);
      openGate(1, myTime1);
    }
  }
  else if (check1 == 1) {
    openGate(1, myTime1);
  }
  else if (check1 == 2) {
    myTime1 = millis();
    check1 = 3;
     digitalWrite(12,0);
    closeGate(2, myTime1);

  }
  else if (check1 == 3) {
    closeGate(1, myTime1);
  }

  if (check2 == 0) {
    if (*(ptr + 1) < 20) {

      myTime2 = millis();
      check2 = 1;
       digitalWrite(13,1);
      openGate(2, myTime2);
    }
  }
  else if (check2 == 1) {
    
    openGate(2, myTime2);
  }
  else if (check2 == 2) {
    myTime2 = millis();
    check2 = 3;
     digitalWrite(13,0);
    closeGate(2, myTime2);

  }
  else if (check2 == 3) {
    closeGate(2, myTime2);
  }

}

int * checkDistance() {
  digitalWrite(trigPin1, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin1, HIGH);

  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW); // Turn off the pulse trigger to stop
  // pulse generation
  // If pulse reached the receiver echoPin
  // become high Then pulseIn() returns the
  // time taken by the pulse to reach the
  // receiver

  long duration1 = pulseIn(echoPin1, HIGH);

  distance[0] = duration1 * 0.0344 / 2;

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  long duration2 = pulseIn(echoPin2, HIGH);
  distance[1] = duration2 * 0.0344 / 2;// Expression to calculate
  return distance;
}

void openGate(int gateno, long instant) {


  if ((millis() - instant) >= 5000) {
   
    if (gateno == 1) {
    
      servo1.write(70);
      check1 = 2;
    }
    else if (gateno == 2 ) {
      servo2.write(110);
     
      check2 = 2;
    }
  }
 
}



void closeGate(int gateno, long instant) {

  if ((millis() - instant) >= 5000) {
    if (gateno == 2) {
     
      servo2.write(0);
      check2 = 0;
    }
    else  if (gateno == 1) {
      servo1.write(180);
      check1 = 0;
    }
  }

}
