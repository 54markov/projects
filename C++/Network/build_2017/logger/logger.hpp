#ifndef _LOGHER_H_
#define _LOGHER_H_

#include <iostream>

using namespace std;

typedef enum {
    DEBUG,
    INFO,
    WARN,
    ERROR
} log_e;

class AbstractLogger {
    protected:
        std::string getLabel(log_e type);

    public:
        virtual ~AbstractLogger();
        virtual void doLog();
};

class ConsoleLogger : public AbstractLogger
{
    public:
        ConsoleLogger();
        ~ConsoleLogger();

        void doLog(log_e type, std::string logMsg);
    
};

#endif  /* LOG_H */