/*
  bot is expected to:
  - stop ~ 10 cm away from the obstacle
  - turn around 180 degrees
  - move back to a point where it can follow the line around the obstacle?
  - record locations of obstacles?
*/

bool obstacle_is_close()
{
  if (LEFT_IR_SENSOR > 10  || RIGHT_IR_SENSOR > 10 // cm away)
  {
    return false;
  }
  return true; // this function returning true should stop the robot because the obstacle is close
  
}

void turn_around()
{
  // this function should call a turning function that I believe Ozan made
  bot.allStop();
  bot.turnRight(180); // degrees
  //"bot.turn(180)" // we pass 180 as the amount of degrees the bot should turn so as to face away from the obstacle
}
