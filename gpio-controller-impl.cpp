#include "gpio-controller-impl.h"

GpioControllerImpl::GpioControllerImpl(std::shared_ptr<FileIo> fileIo, Direction direction, int pinNumber) : 
        fileIo(fileIo), direction(direction), pinNumber(pinNumber)
    {}


void GpioControllerImpl::Write(const std::string& value) const
{
}

std::string GpioControllerImpl::Read() const
{
    return "";
}


