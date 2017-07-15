#ifndef _SERVER_
#define _SERVER_

#include "../logger/logger.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>


class Server
{
    private:
        int servFd_;
        int servPort_;
        int listenQueue_;
        struct sockaddr_in inputAddr_;
        struct sockaddr_in servAddr_;

        ConsoleLogger*     consoleLogger;

        void createSocket();
        void initSocket();
        void setSocketOpt();
        void bindSocket();
        void listenSocket();

    public:
        Server();
        Server(int port, const char* ip, int queue = 10);
        ~Server();

        void createServer();
        void runServer();
        void closeServer();
};


#endif /* _SERVER_ */
