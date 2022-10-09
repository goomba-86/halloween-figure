#include <iostream>
#include <memory>
#include "gpio-controller-impl.h"
#include "file-io-impl.h"

int main(int argc, char** argv)
{
    auto fileIo = std::make_shared<FileIoImpl>();
    auto gpioController = std::make_shared<GpioControllerImpl>(fileIo, Direction::Out, 10);
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
