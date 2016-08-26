#include "main.h"
#include "tcpServer.h"

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        cerr << "usage: " << argv[0] << " [port]\n" << endl;
    }
    
    tcpServer server(atoi(argv[1]));

    server.serverRun();

    return 0;
}