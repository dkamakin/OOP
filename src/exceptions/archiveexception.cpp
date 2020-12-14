#include "exceptions/archiveexception.h"

ArchiveException::ArchiveException(std::string msg) : msg_(msg) {}

std::string ArchiveException::getMessage() {
    return msg_;
}
