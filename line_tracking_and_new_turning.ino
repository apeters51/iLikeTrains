// functions to turn left or right while still moving the bot forward (hopefully smoother turning than before)
void turnLeft()
{
  fr_motor.run(50);
  br_motor.run(50);
  fl_motor.run(-1*40);
  bl_motor.run(-1*40);
}
void turnRight()
{
  fr_motor.run(40);
  br_motor.run(40);
  fl_motor.run(-1*50);
  bl_motor.run(-1*50);
}

// function that moves the bot along the line while both sensors see the line.
// if either of the sensors doesn't see the line, the bot turns until they both do then continues moving forward
// the bot SHOULD totally stop if both sensors don't see the line (indicating the path has ended)
void trackLine()
{
  if (digitalRead(LEFT_LINE_TRACKER) == 1)        // left sensor does not see line
  {
    turnRight();
  }
  else if (digitalRead(RIGHT_LINE_TRACKER) == 1)  // right sensor does not see line
  {
    turnLeft();
  }
  else                                            // both sensors see the line
  {
    moveFoward(40);
  }
}
