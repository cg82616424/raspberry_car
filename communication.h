#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include "control.h"
using namespace std;
class communication
{
    bool circle_info;
    const static int BACKLOG=2;
    const static int PORT=8008;
    int server_socket,client_socket;
    sockaddr_in server_addr;
    sockaddr_in client_addr;
    int err_info;
    pid_t pid;
    control car_control;
public:
    communication();
    int start_listen();
    void process_conn_server(int s);
    virtual ~communication();
};
