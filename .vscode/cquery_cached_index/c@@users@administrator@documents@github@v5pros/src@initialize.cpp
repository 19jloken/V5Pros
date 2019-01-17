#include "main.h"

using namespace pros;

//DEFINES ALL MOTORS
Motor Catapult(1, E_MOTOR_GEARSET_36);
Motor FR(4, E_MOTOR_GEARSET_36,E_MOTOR_ENCODER_DEGREES);
Motor BR(5, E_MOTOR_GEARSET_36,E_MOTOR_ENCODER_DEGREES);
Motor FL(10, E_MOTOR_GEARSET_36,E_MOTOR_ENCODER_DEGREES);
Motor BL(2, E_MOTOR_GEARSET_36,E_MOTOR_ENCODER_DEGREES);
Motor Intake(7, E_MOTOR_GEARSET_06);
// Motor Lift(9, E_MOTOR_GEARSET_36,E_MOTOR_ENCODER_DEGREES);
// Motor Flipper(8, E_MOTOR_GEARSET_18);
Motor BBL(9, E_MOTOR_GEARSET_18,E_MOTOR_ENCODER_DEGREES);
Motor BBR(8, E_MOTOR_GEARSET_18,E_MOTOR_ENCODER_DEGREES);
ADIDigitalIn catapultSwitch (1);

bool getLauncherSensor()
{
	return catapultSwitch.get_value();
}

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		lcd::set_text(2, "I was pressed!");
	} else {
		lcd::clear_line(2);
	}
}

void initialize() {
	lcd::initialize();
	lcd::set_text(1, "Hello PROS User!");
	FR.set_reversed(true);
	BR.set_reversed(true);
	// Lift.set_reversed(true);
	// Flipper.tare_position();

	//TELLS THE MOTORS WHAT TO DO WHEN STOPPED
	Intake.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	// Lift.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  // Flipper.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	Catapult.set_brake_mode(E_MOTOR_BRAKE_HOLD);

	lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
