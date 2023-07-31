// Obstacle avoidance

// function that returns true if ANY of the IR sensors detect an obstacle (false otherwise)
        bool obstacle()
        {
          if (LEFT_IR_SENSOR == LOW || TOP_IR_SENSOR == LOW || RIGHT_IR_SENSOR == LOW)
          {
            return true;
          }
          return false;
        }



// function that tells the robot to navigate thru extraction zone by turning away from obstacles
        void avoidObstacles()
        {
          while (!obstacle)
          {
            moveForward();
          }
          
          if (LEFT_IR_SENSOR == LOW) // yes obstacle
          {
            while (LEFT_IR_SENSOR == LOW) // left sensor still blocked (ADD DIGITAL READS TO EVERYTHING!)
            {
              turnRight();
            }
          }
          else if (RIGHT_IR_SENSOR == LOW) // yes obstacle
          {
            while (RIGHT_IR_SENSOR == LOW) // left sensor still blocked (ADD DIGITAL READS TO EVERYTHING!)
            {
              turnLeft();
            }
          }
          else // only top IR sensor is blocked
          {
            while(LEFT_IR_SENSOR == HIGH) // does not see obstacle
            {
              turnRight();
            }
          }
        }
