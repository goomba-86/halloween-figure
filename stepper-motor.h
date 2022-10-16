#ifndef STEPPERMOTOR_H
#define STEPPERMOTOR_H

#include "gpio-controller.h"

class StepperMotor
{
public:
    StepperMotor(GpioController& pin1, GpioController& pin2, GpioController& pin3, GpioController& pin4, int intervalMilliSeconds);
    StepperMotor(StepperMotor&) = delete;
    StepperMotor& operator=(StepperMotor&) = delete;
    ~StepperMotor();

    void Turn(int count);
    void TurnDegrees(int degrees);

private:
    void DoStep1();
    void DoStep2();
    void DoStep3();
    void DoStep4();
    void DoStep5();
    void DoStep6();
    void DoStep7();
    void DoStep8();
    void Sleep();

    GpioController& pin1;
    GpioController& pin2;
    GpioController& pin3;
    GpioController& pin4;
    int intervalMilliSeconds;
};

#endif
