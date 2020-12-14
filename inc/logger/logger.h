#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include "loggerbridge.h"

using sLogger = std::shared_ptr <class Logger>;

class Logger {
protected:
    sLoggerBridge bridge_;

public:
    explicit Logger(sLoggerBridge bridge);
    virtual void log(const std::string &info) = 0;
    virtual ~Logger() = default;
};

#endif // LOGGER_H
