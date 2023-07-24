#include "MeMegaPi.h"
class Bot { // Class to make accessing motors easier
      public: 
        MeMegaPiDCMotor fr_motor; // Directions are from the perspecitve of looking at the robot from the back
        MeMegaPiDCMotor fl_motor;
        MeMegaPiDCMotor br_motor;
        MeMegaPiDCMotor bl_motor;
        Bot() {}
        void init(MeMegaPiDCMotor fr_motor1, MeMegaPiDCMotor fl_motor1, MeMegaPiDCMotor br_motor1, MeMegaPiDCMotor bl_motor1) { // Constructor
          fr_motor = fr_motor1;
          fl_motor = fl_motor1;
          br_motor = br_motor1;
          bl_motor = bl_motor1;
        }
        void moveForward(int speed) { // Movement member functions
            fr_motor.run(speed);
            fl_motor.run(-1*speed);
            br_motor.run(speed);
            bl_motor.run(-1*speed);
          }
        void moveBackward(int speed) {
            fr_motor.run(-1*speed);
            fl_motor.run(speed);
            br_motor.run(-1*speed);
            bl_motor.run(speed);
          }

        void turnLeft(int degree) { // Ability to turn x degrees still needs to be implemented.
            fr_motor.run(100);
            br_motor.run(100);
          }
        void turnRight(int degree) {
            fl_motor.run(-1*100);
            bl_motor.run(-1*100);
          }

        void allStop(Bot bot) {
            fr_motor.stop();
            fl_motor.stop();
            br_motor.stop();
            bl_motor.stop();
          }
        void lineTracking() {
            right_line_tracker = digitalread(RIGHT_LINE_TRACKER);
            left_line_tracker = digitalread(LEFT_LINE_TRACKER);
            
            if right_line_tracker == 1 & left_line_tracker == 1 {
                  while right_line_tracker == 1 & left_line_tracker == 1 {
                        bot.moveForward(100);
                  }
            }
            else if right_line_tracker != 1 & left_line_tracker == 1 {
                  while right_line_tracker != 1 & left_line_tracker == 1 {
                        bot.turnLeft(5);
                  }
            }
            else if right_line_tracker == 1 & left_line_tracker != 1 {
                  while right_line_tracker == 1 & left_line_tracker != 1 {
                        bot.turnRight(5);
                  }
            }
            else if right_line_tracker != 1 & left_line_tracker != 1 {
                  bot.allStop();
            }
        }
        // Need some sort of obstacle detection as well

        
  };
