#include "server.hpp"

#include <iostream>

using namespace std;

// Default constructor
Server::Server()
{
    this->servFd_      = -1;
    this->servPort_    = 8888;
    this->listenQueue_ = 10;

    bzero((char *)&this->inputAddr_, sizeof(this->inputAddr_));
    
    this->inputAddr_.sin_family      = AF_INET;          // This is an Internet address
    this->inputAddr_.sin_addr.s_addr = INADDR_ANY;       // Let the system figure out our IP address
    this->inputAddr_.sin_port        = htons(servPort_); // This is the port we will listen on

    consoleLogger = new ConsoleLogger();
}

// Parametrized constructor
Server::Server(int port, const char* ip, int queue)
{
    this->servFd_      = -1;
    this->servPort_    = port;
    this->listenQueue_ = queue;

    bzero((char *)&this->inputAddr_, sizeof(this->inputAddr_));
    
    this->inputAddr_.sin_family      = AF_INET;          // This is an Internet address
    this->inputAddr_.sin_addr.s_addr = inet_addr(ip);    // Let the system figure out our IP address
    this->inputAddr_.sin_port        = htons(servPort_); // This is the port we will listen on

    consoleLogger = new ConsoleLogger();
}

// Default destructor
Server::~Server()
{
    delete consoleLogger;
}

// Create socket descriptor
void Server::createSocket()
{
    if ((this->servFd_ = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        throw string("opening socket, atempting to close...");
    }

    consoleLogger->doLog(INFO, "opening socket - complete!");
}

// Init socket
void Server::initSocket()
{
    bzero((char *)&this->servAddr_, sizeof(this->servAddr_));

    this->servAddr_.sin_family      = this->inputAddr_.sin_family;
    this->servAddr_.sin_addr.s_addr = this->inputAddr_.sin_addr.s_addr;
    this->servAddr_.sin_port        = this->inputAddr_.sin_port;

    consoleLogger->doLog(INFO, "init socket - complete!");
}

/* 
 * setsockopt: Handy debugging trick that lets 
 * us rerun the server immediately after we kill it; 
 * otherwise we have to wait about 20 secs. 
 * Eliminates "ERROR on binding: Address already in use" error. 
 */
void Server::setSocketOpt()
{
    int optval = 1;
    setsockopt(this->servFd_, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval , sizeof(int));

    consoleLogger->doLog(INFO, "setting socket option - complete!");
}

/* 
 * bind: associate the parent socket with a port 
 */
void Server::bindSocket()
{
    if (bind(this->servFd_, (struct sockaddr *)&this->servAddr_, sizeof(this->servAddr_)) < 0) {
        throw string("binding, atempting to close...");
    }

    consoleLogger->doLog(INFO, "binding socket - complete!");
}

/* 
 * listen: make this socket ready to accept connection requests 
 */
void Server::listenSocket()
{
    if (listen(this->servFd_, this->listenQueue_) < 0) {
        throw string("listening, atempting to close...");
    }

    consoleLogger->doLog(INFO, "listening socket - complete!");
}

void Server::createServer()
{
    try {
        this->createSocket();
        this->initSocket();
        this->setSocketOpt();
        this->bindSocket();
        this->listenSocket();
    } catch (string err) {
        consoleLogger->doLog(ERROR, err);
        this->closeServer();
        exit(1);
    }
    consoleLogger->doLog(INFO, "create socket - complete!");
}

void Server::closeServer()
{
    close(this->servFd_);
    consoleLogger->doLog(INFO, "closing socket - complete!");
}

void Server::runServer()
{
    this->createServer();

    // TODO
    
    this->closeServer();
}