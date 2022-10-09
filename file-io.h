#ifndef FILEIO_H
#define FILEIO_H

#include <string>

class FileIo
{
public:
    virtual void Write(const std::string& filePath, const std::string& str) const = 0;
    virtual std::string Read(const std::string& filePath) const = 0;

};

#endif
