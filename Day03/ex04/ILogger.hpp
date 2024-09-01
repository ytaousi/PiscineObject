#ifndef ILOGGER_HPP
#define ILOGGER_HPP

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


class ILogger
{
    private:
    public:
        ILogger(){};
        ~ILogger(){};
        virtual void write(std::string) = 0;
};

class FileLogger : public ILogger
{
    private:
        std::string _filename;
    public:
        FileLogger(std::string filename);
        ~FileLogger();
        void write(std::string str);
};

class StreamLogger : public ILogger
{
    private:
        std::ostream &_os;
    public:
        StreamLogger(std::ostream &os);
        ~StreamLogger();
        void write(std::string str);
};

#endif // ILOGGER_HPP