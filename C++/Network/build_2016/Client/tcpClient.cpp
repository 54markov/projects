/* 
 * tcpclient.c - A simple TCP client
 * usage: tcpclient <host> <port>
 */

#include "tcpClient.h"

using namespace std;

tcpClient::tcpClient(char* hostName, int portNum)
{
    hostName_ = hostName;
    portNum_  = portNum;

    this->createSocket();
    this->getHostByName();
    this->buildServerAddr();
}

tcpClient::~tcpClient() {}

void tcpClient::createSocket()
{
    /* socket: create the socket */
    socketFd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd_ < 0) {
        cerr << "ERROR: opening socket" << endl;
    }
}

void tcpClient::getHostByName()
{
    /* gethostbyname: get the server's DNS entry */
    server_ = gethostbyname(hostName_);
    if (!server_) {
        cerr << "ERROR: no such host as" <<  hostName_ << endl;
    }
}

void tcpClient::buildServerAddr()
{
    /* build the server's Internet address */
    bzero((char*)&serverAddr_, sizeof(serverAddr_));
    
    serverAddr_.sin_family = AF_INET;

    bcopy((char*)server_->h_addr,
          (char*)&serverAddr_.sin_addr.s_addr, server_->h_length);

    serverAddr_.sin_port = htons(portNum_);
}

void tcpClient::connectServer()
{
    /* connect: create a connection with the server */
    if (connect(socketFd_, (struct sockaddr*)&serverAddr_, sizeof(struct sockaddr_in)) < 0) {
        cerr << "ERROR: connecting" << endl;
    }
}

void tcpClient::sendMsg(char* msg)
{
    /* send the message line to the server */
    if (write(socketFd_, msg, strlen(msg)) < 0) {
      cerr << "ERROR: writing to socket" << endl;
    }
}

string tcpClient::recvMsg()
{
    /* print the server's reply */
    char buf[BUFSIZE];
    bzero(buf, BUFSIZE);

    if (read(socketFd_, buf, BUFSIZE) < 0) {
        cerr << "ERROR: reading from socket" << endl;
        return NULL;
    }

    return buf;
}

void tcpClient::closeSocket() 
{
    close(socketFd_);
}