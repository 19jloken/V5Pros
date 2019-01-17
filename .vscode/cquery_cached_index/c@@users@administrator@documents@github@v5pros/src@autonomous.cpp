#include "main.h"
#include "Motors.cpp"
#include "pros/llemu.hpp"

bool getLauncherSensor();

//ROBOT FUNCTION VARIABLES
int leftDistance = 0;
int rightDistance = 0;
const int pointTurn = 400;
const int Forwards = 1;
const int Backward = 2;
const int TurnRight = 3;
const int TurnLeft = 4;

//ROBOT FUNCION DEFINITION
void robotFunction(int chassisDirection=0, int chassisSpeed=0, int chassisDistance=0, int catapult=0, int intake=0, int liftHeight=0, int WaitTime=200)
{

  BR.tare_position();
  FR.tare_position();
  BL.tare_position();
  FL.tare_position();
  // Lift.tare_position();
  // Flipper.tare_position();

  if (chassisDirection == Forwards)
  {
    leftDistance = chassisDistance;
    rightDistance = chassisDistance;
  }

  else if (chassisDirection == Backward) //Changes drive speeds to negative if used in function
  {
    leftDistance = -1 * chassisDistance;
    rightDistance = -1 * chassisDistance;
  }

  else if (chassisDirection == TurnRight) //Changes Right side of drive to negative to perform a point turn
  {
    leftDistance = chassisDistance;
    rightDistance = chassisDistance * -1;
  }

  else if (chassisDirection == TurnLeft) //Changes Left side of drive to negative to perform a point turn
  {
    leftDistance = chassisDistance * -1;
    rightDistance = chassisDistance;
  }


  //Uses drive function arguments to set drive direction, speed, and distance
  FR.move_absolute(rightDistance, chassisSpeed);
  BR.move_absolute(rightDistance, chassisSpeed);
  FL.move_absolute(leftDistance, chassisSpeed);
  BL.move_absolute(leftDistance, chassisSpeed);

  //CHECKS TO SEE IF MOTOR IS STILL RUNNING TO CONTINUE LOOP
  while((fabs(BR.get_position()) < abs(chassisDistance-5)))
  {
    delay(5);
    lcd::print(1, "hi %d", BR.get_position());
  }

}

void autonomous()
{

  Catapult.move(-127);
  delay(500);
  Catapult.move(0);
/*  FR.move(-127);
  BR.move(-127);
  FL.move(127);
  BL.move(127);
  delay(1000);
  FR.move(0);
  BR.move(0);
  FL.move(0);
  BL.move(0);
  delay(2);
  FR.move(127);
  BR.move(127);
  FL.move(127);
  BL.move(127);*/

/*  FR.move(127);
  BR.move(127);
  FL.move(-127);
  BL.move(-127);
  delay(450);
  FR.move(0);
  BR.move(0);
  FL.move(0);
  BL.move(0);
  delay(2);
  FR.move(127);
  BR.move(127);
  FL.move(127);
  BL.move(127);
  delay(400);
  FR.move(0);
  BR.move(0);
  FL.move(0);
  BL.move(0);*/




}
