#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "consoleloggerbridge.h"
#include "logger.h"

using sConsoleLogger = std::shared_ptr <class ConsoleLogger>;

class ConsoleLogger : public Logger {
    std::ostream &stream_;

public:
    ConsoleLogger(std::ostream &stream);
    void log(const std::string &info) override;
};

#endif // CONSOLELOGGER_H
