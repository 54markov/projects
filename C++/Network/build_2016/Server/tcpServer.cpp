#include "tcpServer.h"

#include <iostream>

using namespace std;

tcpServer::tcpServer(int port) : port_(port)
{
    this->createSocket();
    this->createServer();
    this->serverBind();
}

tcpServer::~tcpServer() {}
        
void tcpServer::createSocket() 
{
    server_fd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd_ < 0) {
        cerr << "ERROR: Could not create socket" << endl;  
    }
}

void tcpServer::createServer() 
{
    int opt_val = 1;

    server_.sin_family = AF_INET;
            server_.sin_port = htons(port_);
            server_.sin_addr.s_addr = htonl(INADDR_ANY);
            setsockopt(server_fd_, SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof opt_val);
}

void tcpServer::serverBind() 
{
    if (bind(server_fd_, (struct sockaddr*)&server_, sizeof(server_)) < 0) {
        cerr << "ERROR: Could not bind socket" << endl;                
    }
}

void tcpServer::serverListen() 
{
    if (listen(server_fd_, 128) < 0) {
        cerr << "ERROR: Could not listen on socket" << endl;
        return;
    } 
    cout << "Server is listening on " << port_ << endl;
}

void tcpServer::serverRun()
{
    this->serverListen();

    while (true) {
        socklen_t new_client_len = sizeof(client_);

        client_fd_ = accept(server_fd_, (struct sockaddr*)&client_, &new_client_len);
        if (client_fd_ < 0) { 
            cerr << "ERROR: Could not establish new connection" << endl;
        } else {
            cout << "New connection establish on " << client_fd_ << endl;
        }

        while (true) {
            char buf[BUFFER_SIZE];

            int read = recv(client_fd_, buf, BUFFER_SIZE, 0);

            if (!read) {
                break; // done reading
            }

            if (read < 0){
                cerr << "ERROR: Client read failed" << endl;
            } else {
                if (send(client_fd_, buf, read, 0) < 0) {
                    cerr << "ERROR: Client write failed" << endl;
                }                
            }
        }
    }
}