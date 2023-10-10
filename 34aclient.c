/*
============================================================================
Name : 34client.c
Author :Abhishek Rauthan
Description:4. Write a program to create a concurrent server.
 a. use fork
Date:10 oct 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
int main()
{
    int fd_socket;
    struct sockaddr_in addr;
    fd_socket= socket(AF_INET, SOCK_STREAM, 0);
    if (fd_socket== -1)
    {
        printf("There is an error while creating the socket");
        exit(1);
    }
    printf("Client side:socket created successfully");
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    int status=connect(fd_socket,(struct sockaddr *)&addr,sizeof(addr));
    if (status== -1)
    {
        printf("There is an error while connecting to the server");
    }
    else
    {
    printf("Congratulations:Connection established successfully");
    char getdata[80];
    int rb= read(fd_socket,getdata,80);
    if (rb==-1)
        printf("Data can't be receive");

    else
        printf("Data:%s\n",getdata);
        int wb;
        char senddata[]="Hello this side client";
        wb= write(fd_socket,senddata,sizeof(senddata));
    if (wb==-1)
    {
        printf("There is an error while sending data to the server");
    }
    else
    {
        printf("Data successfully sent to the server");
    }
    }
    close(fd_socket);
}