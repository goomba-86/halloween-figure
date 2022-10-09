#include "file-io-mock.h"
#include "gpio-controller-impl.h"

TEST(GpioControllerImplTest, TestThatPinIsInitializedToOutputCorrectly)
{
    auto fileIoMock = std::make_shared<FileIoMock>();
    GpioControllerImpl gpioController(fileIoMock, Direction::Out, 24); 
    ASSERT_EQ(1, 0);
}

