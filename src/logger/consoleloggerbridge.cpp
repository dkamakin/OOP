#include "logger/consoleloggerbridge.h"

void ConsoleLoggerBridge::log(std::ostream *stream, const std::string &info) {
    *stream << info;
}
