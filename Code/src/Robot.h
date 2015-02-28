
#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "LiveWindow/LiveWindow.h"




class Robot : public IterativeRobot {
public:
	LiveWindow *lw;
	DriveController driveController;
	LiftController liftController;
	OperatorController operatorController;
	AutonomousControl autonomousControl;

				Robot();
	virtual		~Robot();
	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif