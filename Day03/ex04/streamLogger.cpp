#include "ILogger.hpp"

StreamLogger::StreamLogger(std::ostream &os) : _os(os)
{
    ;
}

StreamLogger::~StreamLogger()
{
    ;
}

void StreamLogger::write(std::string str)
{
    _os << str;
}

