#include "ILogger.hpp"

FileLogger::FileLogger(std::string filename)
{
    this->_filename = filename;
}

FileLogger::~FileLogger()
{
    ;
}

void FileLogger::write(std::string str)
{
    std::ofstream file(this->_filename.c_str(), std::ios_base::app | std::ios_base::out);
    if (file.is_open())
    {
        file << str;
        file.close();
    }
}