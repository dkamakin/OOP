#include "logger/consolelogger.h"

ConsoleLogger::ConsoleLogger(std::ostream &stream) : Logger(sConsoleLoggerBridge(new ConsoleLoggerBridge)), stream_(stream) {}

void ConsoleLogger::log(const std::string &info) {
    if (stream_)
        bridge_->log(&stream_, info);
}
