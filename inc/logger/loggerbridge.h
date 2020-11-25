#ifndef LOGGERBRIDGE_H
#define LOGGERBRIDGE_H

#include <memory>
#include <ostream>

using sLoggerBridge = std::shared_ptr <class LoggerBridge>;

class LoggerBridge {
public:
    virtual void log(std::ostream *stream, const std::string &info) = 0;
    ~LoggerBridge() = default;
};

#endif // LOGGERBRIDGE_H
