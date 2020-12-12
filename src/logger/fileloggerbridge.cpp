#include "logger/fileloggerbridge.h"

void FileLoggerBridge::log(std::ostream *stream, const std::string &info) {
    *stream << info;
}
