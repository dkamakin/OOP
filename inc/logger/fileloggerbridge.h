#ifndef FILELOGGERBRIDGE_H
#define FILELOGGERBRIDGE_H

#include "loggerbridge.h"

class FileLoggerBridge : public LoggerBridge {
public:
    void log(std::ostream *stream, const std::string &info) override;
};

#endif // FILELOGGERBRIDGE_H
