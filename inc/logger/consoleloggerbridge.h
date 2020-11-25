#ifndef CONSOLELOGGERBRIDGE_H
#define CONSOLELOGGERBRIDGE_H

#include "loggerbridge.h"

using sConsoleLoggerBridge = std::shared_ptr <class ConsoleLoggerBridge>;

class ConsoleLoggerBridge : public LoggerBridge {
public:
    void log(std::ostream *stream, const std::string &info) override;
};

#endif // CONSOLELOGGERBRIDGE_H
