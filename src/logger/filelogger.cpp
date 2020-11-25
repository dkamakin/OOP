#include "logger/filelogger.h"

FileLogger::FileLogger(const std::string &fileName) : Logger(sLoggerBridge(new FileLoggerBridge)) {
    stream_ = sofstream(new std::ofstream(fileName));
}

void FileLogger::log(const std::string &info) {
    if (stream_)
        bridge_->log(stream_.get(), info);
}

FileLogger::~FileLogger() {
    if (stream_)
        stream_->close();
    stream_ = nullptr;
}
