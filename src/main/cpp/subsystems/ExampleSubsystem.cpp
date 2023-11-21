// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ExampleSubsystem.h"

ExampleSubsystem::ExampleSubsystem() {
  // Implementation of subsystem constructor goes here.
}

frc2::CommandPtr ExampleSubsystem::ExampleMethodCommand() {
  // Inline construction of command goes here.
  // Subsystem::RunOnce implicitly requires `this` subsystem.
  return RunOnce( [this] { motor.Set(1.0); } );
}

frc2::CommandPtr ExampleSubsystem::MoveMotorCommand( double controllerInput ) {
  // Example of an "expanded" lambda function.
  // Works the same way if this was all put right into RunOnce();
  auto lambda = [this, &controllerInput]()
  {
    // Set the goal of the PID Controller.
    pid.SetReference(controllerInput * 42.0, rev::CANSparkMax::ControlType::kVelocity);
  };

  return RunOnce(lambda);
}

bool ExampleSubsystem::ExampleCondition() {
  // Query some boolean state, such as a digital sensor.
  return false;
}

void ExampleSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void ExampleSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
