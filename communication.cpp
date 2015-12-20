#include "communication.h"
communication::communication()
{
    circle_info=true;
    //create server socket
    server_socket=socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket<0)
    {
        cout<<"init server_socket error,return value is"<<server_socket<<endl;
        cout<<"program will exit -1"<<endl;
        exit(-1);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    server_addr.sin_port=htons(communication::PORT);
    err_info=bind(server_socket,(sockaddr*)&server_addr,sizeof(server_addr));
    if(err_info<0)
    {
        cout<<"bind addr and port error, return value is"<<err_info<<endl;
        cout <<"the program will exit -2"<<endl;
        exit(-2);
    }

}
void communication::process_conn_server(int s)
{
    ssize_t size=0;
    char buffer[1024];
    while (true) {
        size=read(s,buffer,1024);
	cout<<int(buffer[0])<<endl;
        if(size==0)
        {
	    cout<<"no data"<<endl;
            return;
        }
        //buffer 0 must be asdw or t,
        int return_val=car_control.translate_kbd_to_action(int(buffer[0]));
        buffer[0]=char(return_val);
        write(s, buffer, strlen(buffer)+1);
    }
}
int communication::start_listen()
{
    err_info=listen(server_socket, communication::BACKLOG);
    if(err_info<0)
    {
        cout<<"listen addr and port error, return value is"<<err_info<<endl;
        cout <<"the program will exit -3"<<endl;
        exit(-3);
    }
    int fail_time(0);
    while (circle_info) {
        cout<<"listening...."<<endl;
        socklen_t addrlen = sizeof(sockaddr);
        client_socket=accept(server_socket, (sockaddr*)&client_addr, &addrlen);
        if(client_socket<0)
        {
            cout<<"warning: accept error,continue"<<endl;
            ++fail_time;
            if(fail_time>3){
                close(client_socket);
            }
            continue;
        }
        pid=fork();
        if(pid==0)
        {
            close(server_socket);
            process_conn_server(client_socket);
        }
        else
        {
            close(client_socket);

        }
    }
    return 0;
}
communication::~communication()
{

}
