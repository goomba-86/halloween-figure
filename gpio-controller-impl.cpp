#include "gpio-controller-impl.h"

GpioControllerImpl::GpioControllerImpl(std::shared_ptr<FileIo> fileIo, Direction direction, int pinNumber) : 
        fileIo(fileIo), direction(direction), gpioPinPath(gpioSysfsPath + "/gpio" + std::to_string(pinNumber))
{
    fileIo->Write(gpioSysfsPath + "/export", std::to_string(pinNumber));  
    if(direction == Direction::In)
    {
        fileIo->Write(gpioPinPath + "/direction", "in");
    }
    else
    {
        fileIo->Write(gpioPinPath + "/direction", "out");
    }
}


void GpioControllerImpl::Write(PinValue value) const
{
}

std::string GpioControllerImpl::Read() const
{
    return "";
}


