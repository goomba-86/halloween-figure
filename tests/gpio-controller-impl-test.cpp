#include "file-io-mock.h"
#include "gpio-controller-impl.h"

using testing::StrEq;
using testing::Return;

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

TEST(GpioControllerImplTest, TestThatHighValueIsWrittenCorrectly)
{
    auto fileIoMock = std::make_shared<FileIoMock>();
    EXPECT_CALL(*fileIoMock, Write("/sys/class/gpio/export", "24"));
    EXPECT_CALL(*fileIoMock, Write("/sys/class/gpio/gpio24/direction", "out"));
    EXPECT_CALL(*fileIoMock, Write("/sys/class/gpio/gpio24/value", "1"));
    GpioControllerImpl gpioController(fileIoMock, Direction::Out, 24); 
    gpioController.Write(PinValue::High);
}

TEST(GpioControllerImplTest, TestThatLowValueIsWrittenCorrectly)
{
    auto fileIoMock = std::make_shared<FileIoMock>();
    EXPECT_CALL(*fileIoMock, Write("/sys/class/gpio/export", "24"));
    EXPECT_CALL(*fileIoMock, Write("/sys/class/gpio/gpio24/direction", "out"));
    EXPECT_CALL(*fileIoMock, Write("/sys/class/gpio/gpio24/value", "0"));
    GpioControllerImpl gpioController(fileIoMock, Direction::Out, 24); 
    gpioController.Write(PinValue::Low);
}

TEST(GpioControllerImplTest, TestThatPinValueIsReadCorrectly)
{
    auto fileIoMock = std::make_shared<FileIoMock>();
    EXPECT_CALL(*fileIoMock, Write("/sys/class/gpio/export", "24"));
    EXPECT_CALL(*fileIoMock, Write("/sys/class/gpio/gpio24/direction", "in"));
    EXPECT_CALL(*fileIoMock, Read("/sys/class/gpio/gpio24/value"))
        .WillRepeatedly(Return("1"));
    GpioControllerImpl gpioController(fileIoMock, Direction::In, 24); 
    ASSERT_EQ("1", gpioController.Read());
}
