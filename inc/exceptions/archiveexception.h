#ifndef ARCHIVEEXCEPTION_H
#define ARCHIVEEXCEPTION_H

#include <string>

class ArchiveException {
    std::string msg_;

public:
    explicit ArchiveException(std::string msg);
    std::string& getMessage();
};

#endif // ARCHIVEEXCEPTION_H
