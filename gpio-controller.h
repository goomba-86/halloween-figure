#ifndef GPIOCONTROLLER_H
#define GPIOCONTROLLER_H

#include <string>

enum class Direction
{
    In,
    Out
};

class GpioController
{
public:
    virtual ~GpioController() = default;
    virtual void Write(const std::string& value) const = 0;
    virtual std::string Read() const = 0;

    inline static const std::string gpioSysfsPath = "/sys/class/gpio";
};

#endif
