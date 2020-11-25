#include "inc/logger/consoleloggerbridge.h"
#include <ostream>

void ConsoleLoggerBridge::log(std::ostream *stream, const std::string &info) {
    *stream << info;
}
