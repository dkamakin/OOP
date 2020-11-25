#ifndef LOGGERCONTEXT_H
#define LOGGERCONTEXT_H

#include <set>
#include "logger.h"
#include "consolelogger.h"
#include "filelogger.h"

using uLoggerContext = std::unique_ptr <class LoggerContext>;

class LoggerContext {
    std::set<sLogger> listeners_;

    static uLoggerContext logger;

public:
    LoggerContext() = default;
    ~LoggerContext() = default;

    static LoggerContext& getInstance();
    static void initInstance();
    static void deleteInstance();

    void log(const std::string &info);
    void subscribe(Logger *logger);
    void unsubscribe(Logger *logger);

    friend LoggerContext& operator<<(LoggerContext &context, const std::string &info);
};

#endif // LOGGERCONTEXT_H
