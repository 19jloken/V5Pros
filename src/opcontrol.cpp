#include "main.h"
#include "Motors.cpp"
#include "pros/api_legacy.h"
#include "api.h"

using namespace pros;



void opcontrol() {

  //CONTROLLERS
  Controller main(E_CONTROLLER_MASTER);
  Controller partner(E_CONTROLLER_PARTNER);

  while(true)
  {

/*    if (joystickIsConnected(E_CONTROLLER_PARTNER))
    {
      // Use a two controller control scheme
    }
    else
    {
      // Just use a single controller control scheme
    }*/

    //DRIVE WITH STRAFE
    FL.move(main.get_analog(ANALOG_LEFT_Y) + ((main.get_digital(E_CONTROLLER_DIGITAL_R1) + main.get_digital(E_CONTROLLER_DIGITAL_R2)) * -63) + ((main.get_digital(E_CONTROLLER_DIGITAL_L1) + main.get_digital(E_CONTROLLER_DIGITAL_L2)) * 63));
    FR.move(main.get_analog(ANALOG_RIGHT_Y) + ((main.get_digital(E_CONTROLLER_DIGITAL_R1) + main.get_digital(E_CONTROLLER_DIGITAL_R2)) * -63) + ((main.get_digital(E_CONTROLLER_DIGITAL_L1) + main.get_digital(E_CONTROLLER_DIGITAL_L2)) * 63));
    BL.move(main.get_analog(ANALOG_LEFT_Y) + ((main.get_digital(E_CONTROLLER_DIGITAL_R1) + main.get_digital(E_CONTROLLER_DIGITAL_R2)) * 63) + ((main.get_digital(E_CONTROLLER_DIGITAL_L1) + main.get_digital(E_CONTROLLER_DIGITAL_L2)) * -63));
    BR.move(main.get_analog(ANALOG_RIGHT_Y) + ((main.get_digital(E_CONTROLLER_DIGITAL_R1) + main.get_digital(E_CONTROLLER_DIGITAL_R2)) * 63) + ((main.get_digital(E_CONTROLLER_DIGITAL_L1) + main.get_digital(E_CONTROLLER_DIGITAL_L2)) * -63));

    //INTAKE
    if (partner.get_digital(DIGITAL_R1) == 1)
    {
      Intake.move(-127);
    }
    else if (partner.get_digital(DIGITAL_R2) == 1)
    {
      Intake.move(127);
    }
    else
    {
      Intake.move(0);
      Intake.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
    }

    //LIFT
    Lift.move(partner.get_analog(ANALOG_RIGHT_Y)/1.5);
    Lift.set_brake_mode(E_MOTOR_BRAKE_HOLD);

    //CAP FLIPPER

    if (partner.get_digital(DIGITAL_RIGHT) == 1)
    {
      Flipper.move(30);
    }
    else if (partner.get_digital(DIGITAL_LEFT) == 1)
    {
      Flipper.move(-30);
    }
    else
    {
      Flipper.move(0);
      Flipper.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    }

    //CATAPULT
/*    if (main.get_digital(DIGITAL_A) == 1 && getLauncherSensor() == 1)
    {

    }*/
    if (main.get_digital(DIGITAL_A) == 1)
    {
      Catapult.move(-127);
    }
    else
    {
      Catapult.move(0);
      Catapult.set_brake_mode(E_MOTOR_BRAKE_HOLD);
    }



	  lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
    (lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
    (lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
    int left = main.get_analog(ANALOG_LEFT_Y);
    int right = main.get_analog(ANALOG_RIGHT_Y);

    delay(20);
  }
}
