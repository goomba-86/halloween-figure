#include "file-io-mock.h"
#include "gpio-controller-impl.h"

using testing::StrEq;

TEST(GpioControllerImplTest, TestThatPinIsInitializedToOutputCorrectly)
{
    auto fileIoMock = std::make_shared<FileIoMock>();
    EXPECT_CALL(*fileIoMock, Write("/sys/class/gpio/export", "24"));
    EXPECT_CALL(*fileIoMock, Write("/sys/class/gpio/gpio24/direction", "out"));
    GpioControllerImpl gpioController(fileIoMock, Direction::Out, 24); 
}

TEST(GpioControllerImplTest, TestThatPinIsInitializedToInputCorrectly)
{
    auto fileIoMock = std::make_shared<FileIoMock>();
    EXPECT_CALL(*fileIoMock, Write("/sys/class/gpio/export", "24"));
    EXPECT_CALL(*fileIoMock, Write("/sys/class/gpio/gpio24/direction", "in"));
    GpioControllerImpl gpioController(fileIoMock, Direction::In, 24); 
}
