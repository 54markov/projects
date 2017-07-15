/* 
 * tcpclient.c - A simple TCP client
 * usage: tcpclient <host> <port>
 */
#include "main.h"
#include "tcpClient.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

#include <iostream>

using namespace std;

using namespace std;

int main(int argc, char **argv) 
{
    int portNum;
    char *hostName;

    /* Check command line arguments */
    if (argc != 3) {
       cerr << "usage:" << argv[0] << " <hostname> <port>" << endl;
       return -1;
    }

    hostName = argv[1];
    portNum = atoi(argv[2]);

    tcpClient client(hostName, portNum);

    client.connectServer();
    
    client.sendMsg((char*)"echo");   

    cout << client.recvMsg() << endl;

    client.closeSocket();

    return 0;
}