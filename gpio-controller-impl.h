#ifndef GPIOCONTROLLERIMPL_H
#define GPIOCONTROLLERIMPL_H

#include "gpio-controller.h"
#include "file-io.h"
#include <memory>

class GpioControllerImpl : public GpioController
{
public:
    GpioControllerImpl(std::shared_ptr<FileIo> fileIo, Direction direction, int pinNumber);
    void Write(const std::string& value) const override;
    std::string Read() const override;
private:
    std::shared_ptr<FileIo> fileIo;
    Direction direction;
    int pinNumber;

};

#endif
