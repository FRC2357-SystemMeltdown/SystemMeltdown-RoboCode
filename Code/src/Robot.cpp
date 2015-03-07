#include "WPILib.h"
#include "DriveController.h"
#include "LiftController.h"
#include "OperatorController.h"
#include "AutonomousControl.h"
#include "LiveWindow/LiveWindow.h"
#include "Robot.h"

/**
 * This is a demo program showing how to use Mecanum control with the RobotDrive class.
 */
Robot::Robot() :
			driveController(1, 0, 2, 3, 0),
			liftController(4, 1, 3, 4),
			operatorController(driveController, liftController, 0, 1),
			autonomousControl(driveController, liftController)
{

}

Robot::~Robot(){

}

void Robot::RobotInit()
{
		lw = LiveWindow::GetInstance();
}

void Robot::DisabledInit()
{

}

void Robot::DisabledPeriodic()
{

}

void Robot::AutonomousInit()
{

}

void Robot::AutonomousPeriodic()
{
	autonomousControl.RunModeOne();
	driveController.UpdateMotors();
}

void Robot::TeleopInit()
{
	//liftController.StartPID();
	liftController.StartEncoder();
	driveController.SetSafetyEnabled(false);
	driveController.SetExpiration(0.25);
	TeleopPeriodic();

}

void Robot::TeleopPeriodic()
{
	operatorController.Run();
	driveController.UpdateMotors();
	//std::cout << liftController.EncoderGet() << std::endl;
}

void Robot::TestPeriodic()
{
	lw->Run();
	driveController.UpdateMotors();
}


START_ROBOT_CLASS(Robot);
