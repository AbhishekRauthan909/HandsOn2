/*
============================================================================
Name : 33.c
Author :Abhishek Rauthan
Description:Write a program to communicate between two machines using socket.
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
    int socket_fd, connect_fd;
    struct sockaddr_in addr, client;
    socket_fd=socket(AF_INET,SOCK_STREAM,0);
    if (socket_fd== -1)
    {
        printf("There is an error while creating the socket");
        exit(1);
    }
    printf("Server:Socket created successfully");
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    int bstatus= bind(socket_fd,(struct sockaddr *)&addr,sizeof(addr));
    if (bstatus== -1)
    {
        printf("There is an error while binding the socket");
        exit(0);
    }
    printf("Socket successfully binded\n");
    int lstatus;
    lstatus=listen(socket_fd,2);
    if (lstatus==-1)
    {
        printf("Error in listening\n");
        exit(1);
    }
    printf("Server is now listening for connection\n");
    int clsize;//client size
    clsize=(int)sizeof(client);
    connect_fd=accept(socket_fd,(struct sockaddr *)&client,&clsize);
    if (connect_fd==-1)
        printf("There is an error while connecting to the client");
    else
    {
        int wb;
        char sendata[]="Hello this side server";
        wb=write(connect_fd,sendata,sizeof(sendata));
        if (wb==-1)
            printf("There is an error while sending the data");
        else
            printf("Data sent successfully to the client!\n");
        int rb;
        char rcvdata[80];
        rb=read(connect_fd,rcvdata,sizeof(rcvdata));
        if (rb==-1)
            printf("There is an error while reading the data\n");
        else
            printf("Client data:%s\n",rcvdata);
        close(connect_fd);
    }
    close(socket_fd);
}