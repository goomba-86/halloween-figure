#include "stepper-motor.h"
#include <thread>
#include <chrono>

StepperMotor::StepperMotor(GpioController& pin1, GpioController& pin2, GpioController& pin3, GpioController& pin4, int intervalMilliSeconds) : 
    pin1(pin1), pin2(pin2), pin3(pin3), pin4(pin4), intervalMilliSeconds(intervalMilliSeconds) 
{
    pin1.SetDirection(Direction::Out);
    pin2.SetDirection(Direction::Out);
    pin3.SetDirection(Direction::Out);
    pin4.SetDirection(Direction::Out);
}

StepperMotor::~StepperMotor()
{
}

void StepperMotor::Turn(int count)
{
    for(int i = 0; i < count; i++)
    {
        DoStep1();
        DoStep2();
        DoStep3();
        DoStep4();
        DoStep5();
        DoStep6();
        DoStep7();
        DoStep8();
    }
}

void StepperMotor::TurnSteps(int steps)
{
    for(int i = 0; i < steps; i++)
    {
        Turn(i);
    }
}

void StepperMotor::TurnDegrees(int degrees)
{
    Turn(degrees * 512 / 360);
}

void StepperMotor::DoStep1()
{
    pin4.Write(PinValue::High);
    Sleep();
    pin4.Write(PinValue::Low);
}

void StepperMotor::DoStep2()
{
    pin4.Write(PinValue::High);
    pin3.Write(PinValue::High);
    Sleep();
    pin4.Write(PinValue::Low);
    pin3.Write(PinValue::Low);
}

void StepperMotor::DoStep3()
{
    pin3.Write(PinValue::High);
    Sleep();
    pin4.Write(PinValue::Low);
}

void StepperMotor::DoStep4()
{
    pin3.Write(PinValue::High);
    pin2.Write(PinValue::High);
    Sleep();
    pin2.Write(PinValue::Low);
    pin3.Write(PinValue::Low);
}

void StepperMotor::DoStep5()
{
    pin2.Write(PinValue::High);
    Sleep();
    pin2.Write(PinValue::Low);
}

void StepperMotor::DoStep6()
{
    pin2.Write(PinValue::High);
    pin1.Write(PinValue::High);
    Sleep();
    pin1.Write(PinValue::Low);
    pin2.Write(PinValue::Low);
}

void StepperMotor::DoStep7()
{
    pin1.Write(PinValue::High);
    Sleep();
    pin1.Write(PinValue::Low);
}

void StepperMotor::DoStep8()
{
    pin1.Write(PinValue::High);
    pin4.Write(PinValue::High);
    Sleep();
    pin4.Write(PinValue::Low);
    pin1.Write(PinValue::Low);
}

void StepperMotor::Sleep()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(intervalMilliSeconds));
}

