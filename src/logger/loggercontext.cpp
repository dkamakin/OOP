#include "logger/loggercontext.h"

uLoggerContext LoggerContext::logger = nullptr;

LoggerContext& LoggerContext::getInstance() {
    if (!logger)
        logger = uLoggerContext(new LoggerContext());
    return *logger;
}

void LoggerContext::initInstance() {
    getInstance();
}

void LoggerContext::deleteInstance() {
    logger = nullptr;
}

void LoggerContext::subscribe(Logger *logger) {
    listeners_.insert(sLogger(logger));
}

void LoggerContext::unsubscribe(Logger *logger) {
    listeners_.erase(sLogger(logger));
}

void LoggerContext::log(const std::string &info) {
    for (auto &listener : listeners_)
        listener->log(info);
}

LoggerContext& operator<<(LoggerContext &context, const std::string &info) {
    context.log(info);
    return context;
}
