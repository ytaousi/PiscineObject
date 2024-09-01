#include "ILogger.hpp"

std::string intToString(int value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

int main()
{
    StreamLogger sl(std::cout);
    StreamLogger sl2(std::cout);
    FileLogger fl("file.log");
    FileLogger fl2("file.log");
    std::vector<ILogger *> loggers;

    loggers.push_back(&sl);
    loggers.push_back(&fl);
    loggers.push_back(&sl2);
    loggers.push_back(&fl2);

    int i = 0;
    int j = 0;
    for (std::vector<ILogger *>::iterator it = loggers.begin(); it != loggers.end(); it++)
    {
        std::string fileLoggerID = intToString(i + 1);
        std::string streamLoggerID = intToString(j + 1);
        if(dynamic_cast<FileLogger*>(*it))
        {
            (*it)->write("Hello, World! ");
            (*it)->write("FileLogger ");
            (*it)->write(fileLoggerID); 
            (*it)->write(" Working Fine!\n");
            i++;
        }
        if(dynamic_cast<StreamLogger*>(*it))
        {
            (*it)->write("Hello, World!\n");
            (*it)->write("StreamLogger ");
            (*it)->write(streamLoggerID); 
            (*it)->write(" Working Fine!\n");
            j++;
        }
    }

    std::cout << "-----------------" << std::endl;
    return (0);
}