// Obstacle avoidance

// function that returns true if ANY of the IR sensors detect an obstacle (false otherwise)
bool obstacle()
{
        if (digitalRead(LEFT_IR_SENSOR) == LOW || digitalRead(TOP_IR_SENSOR) == LOW || digitalRead(RIGHT_IR_SENSOR) == LOW) // if any of the sensors detect an obstacle, return true
        {
                return true;
        }
        return false;
}



// function that tells the robot to navigate thru extraction zone by turning away from obstacles
void avoidObstacles()
{
        if (digitalRead(LEFT_IR_SENSOR) == LOW)       // yes obstacle detected by left sensor
        {
                turnRight();
        }
        else if (digitalRead(RIGHT_IR_SENSOR) == LOW) // yes obstacle detected by right sensor
        {
                turnLeft();
        }
        else if (digitalRead(LEFT_IR_SENSOR) == HIGH) // yes obstacle detected by top sensor (arbitrary turning right to make it so that left sensor sees obstacle)
        {
                turnRight();
        }
        else                                          // none of the sensors see obstacles
        {
                moveForward();
        }
}
