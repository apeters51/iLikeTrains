#include "MeMegaPi.h"
#include <SoftwareSerial.h>

int LEFT_IR_SENSOR = A6;
int TOP_IR_SENSOR = A7;
int RIGHT_IR_SENSOR = A8;
int RIGHT_LED = A14;
int LEFT_LED = A13;
int left = 0; // initialize left hand motion counter
int right = 0; //initialize right hand motion counter
int right_motion = digitalRead(RIGHT_IR_SENSOR); // creates variable to read if motion on the right is detected
int left_motion = digitalRead(LEFT_IR_SENSOR);
int top_motion = digitalRead(TOP_IR_SENSOR);
int input= 0;


//MeInfraredReceiver LEFT_IR_SENSOR (6);
//MeInfraredReceiver TOP_IR_SENSOR (7);
//MeInfraredReceiver RIGHT_IR_SENSOR (8);

void setup() {
  // put your setup code here, to run once:
  pinMode(LEFT_IR_SENSOR, INPUT);
  pinMode(RIGHT_IR_SENSOR, INPUT);
  pinMode(TOP_IR_SENSOR, INPUT);

  pinMode(RIGHT_LED, OUTPUT);
  pinMode(LEFT_LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
signal_exchange();
  rendevous_mode();
}


void rendevous_mode() {
  if (right_motion == 1) { //counter for different direction hand signals
    right = right + 1;
    input = input + 1;
  }
  else if (left_motion == 1) {
    left = left + 1;
    input = input + 1;
  }
  while (input == 4) {
    if (right == 3 && left == 1) { // this will be the correct hand signal (RRRL)
      digitalWrite(RIGHT_LED, HIGH);
      delay(2000); //one long flash to signal successful code
      digitalWrite(RIGHT_LED, LOW);

      right = 0;
      left = 0;
      input = 0;
    }
    else {
      digitalWrite(LEFT_LED, HIGH);
      delay(2000);
      digitalWrite(LEFT_LED, LOW); // signal incorrect

      digitalWrite(RIGHT_LED, HIGH);
      delay(500);
      digitalWrite(RIGHT_LED, LOW);
      delay(500);
      digitalWrite(RIGHT_LED, HIGH)
      delay(500);
      digitalWrite(RIGHT_LED, LOW); // flash again to show hand signal read mode
      right = 0;
      left = 0;
      input = 0;
    }
  }
}



}
void signal_exchange() {



  if (right_motion == 1 || left_motion == 1 || top_motion == 1) {
    //stop robot motion here somehow
    delay(3000); //3 second delay per requirements

    //led flash to verify robot is not a fake

    delay(3000);
    digitalWrite(RIGHT_LED, HIGH);
    delay(500);
    digitalWrite(RIGHT_LED, LOW);
    digitalWrite(LEFT_LED, HIGH);
    delay(500);
    digitalWrite(LEFT_LED, LOW);

    // led flash to signal hand signal read mode
    delay(3000);
    digitalWrite(RIGHT_LED, HIGH);
    delay(500);
    digitalWrite(RIGHT_LED, LOW);
    delay(500);
    digitalWrite(RIGHT_LED, HIGH)
    delay(500);
    digitalWrite(RIGHT_LED, LOW);

    right_motion = 0;
    left_motion = 0;
    top_motion = 0;

    rendevous_mode()
  }
}
