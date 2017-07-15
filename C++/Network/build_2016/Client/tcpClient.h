#ifndef _TCP_CLIENT_H_
#define _TCP_CLIENT_H_

#include <iostream>
#include <string>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

#define BUFSIZE 1024

class tcpClient
{
    private:
        int                 socketFd_;
        int                 portNum_;
        char*               hostName_;
        struct sockaddr_in  serverAddr_;
        struct hostent*     server_;

    public:
        tcpClient(char* hostName, int portNum);
        ~tcpClient();

        void createSocket();
        void closeSocket();
        
        void getHostByName();
        void buildServerAddr();
        
        void connectServer();

        void sendMsg(char* msg);
        std::string recvMsg();
};

#endif