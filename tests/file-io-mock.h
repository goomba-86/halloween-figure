#ifndef FILEIOMOCK_H
#define FILEIOMOCK_H

#include "file-io.h"
#include <gmock/gmock.h>

class FileIoMock : public FileIo
{
public:
    MOCK_METHOD(void, Write, (const std::string& filePath, const std::string& str), (const, override));
    MOCK_METHOD(std::string, Read, (const std::string& filePath), (const, override));
};

#endif
