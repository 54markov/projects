#include "logger.hpp"

#include <iostream>
#include <string>

std::string AbstractLogger::getLabel(log_e type)
{
    std::string label;
    
    switch(type) 
    {
        case DEBUG: label = "[DEBUG] "; break;
        case INFO:  label = "[INFO] ";  break;
        case WARN:  label = "[WARN] ";  break;
        case ERROR: label = "[ERROR] "; break;
    }
    return label;
}

AbstractLogger::~AbstractLogger() { }
void AbstractLogger::doLog() { }


ConsoleLogger::ConsoleLogger() {}
ConsoleLogger::~ConsoleLogger() {}

void ConsoleLogger::doLog(log_e type, std::string logMsg)
{
    cout << getLabel(type) << logMsg << endl;
}