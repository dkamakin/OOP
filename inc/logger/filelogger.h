#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <fstream>
#include "logger.h"
#include "fileloggerbridge.h"

using sofstream = std::shared_ptr <std::ofstream>;
using sFileLogger = std::shared_ptr <class FileLogger>;

class FileLogger : public Logger {
    sofstream stream_;

public:
    explicit FileLogger(const std::string &fileName);
    ~FileLogger() override;

    void log(const std::string &info) override;
};

#endif // FILELOGGER_H
