#include "server/server.hpp"

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc < 3) {
        cerr << "usage: " << argv[0] << " [ip] [port]" << endl;
        return -1;
    }

    cout << atoi(argv[2]) << endl;
    cout << argv[1] << endl;
    
    Server testServer(atoi(argv[2]), argv[1]);

    testServer.runServer();

    return 0;
}