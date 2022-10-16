#include <iostream>
#include <memory>
#include "gpio-controller-impl.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "file-io-impl.h"
#include "stepper-motor.h"


void Sleep(int millisencods);

int main(int argc, char** argv)
{
    auto fileIo = std::make_shared<FileIoImpl>();
    std::cout << "Moving started." << std::endl;
    GpioControllerImpl pin1(fileIo, Direction::Out, 12);
    GpioControllerImpl pin2(fileIo, Direction::Out, 16);
    GpioControllerImpl pin3(fileIo, Direction::Out, 20);
    GpioControllerImpl pin4(fileIo, Direction::Out, 21);
    StepperMotor motor(pin1, pin2, pin3, pin4, 5);


    while(true)
    {
        motor.TurnDegrees(30);
        Sleep(3000);
        motor.TurnDegrees(-30);
        Sleep(3000);
    }
    return 0;
}

void Sleep(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
