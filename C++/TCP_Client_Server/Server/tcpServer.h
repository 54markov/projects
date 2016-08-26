#ifndef _TCP_SERVER_H_
#define _TCP_SERVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

class tcpServer
{
    private:
        int port_;
        int server_fd_;
        int client_fd_;

        struct sockaddr_in server_;
        struct sockaddr_in client_;

    public:
        tcpServer(int port);
        ~tcpServer();
        
        void createSocket();
        void createServer();
        void serverBind();
        void serverListen();
        void serverRun();
};

#endif