/*
============================================================================
Name : 34aserver.c
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
    int socket_fd,connect_fd;
    struct sockaddr_in addr,client;
    socket_fd=socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd== -1)
    {
        printf("Error while creating socket");
        exit(0);
    }
    printf("Server:Socket created successfully");
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    int bind_status=bind(socket_fd,(struct sockaddr *)&addr,sizeof(addr));
    if (bind_status==-1)
    {
        printf("There is an error while binding the socket to address");
        exit(1);
    }
    printf("Socket binded to address successfully\n");
    int lstatus=listen(socket_fd,2);
    if (lstatus==-1)
    {
        printf("There is an error while listening");
        exit(1);
    }
    printf("Listening in the server");
    char ch='Y';
    while(ch=='Y')
    {
        int csize=(int)sizeof(client);
        connect_fd=accept(socket_fd,(struct sockaddr *)&client,&csize);
        if (connect_fd==-1)
            printf("There is an error while connecting to client");
        else
        {
            if (fork()==0)
            {
                char send[]="Hello this side is server";
                int wb=write(connect_fd,send,sizeof(send));
                if (wb==-1)
                    printf("There is an error while writing");
                else
                    printf("Data successfully sent to client\n");
                char rec[80];
                int rb=read(connect_fd,rec,80);
                if (rb==-1)
                    printf("There is an error while reading\n");
                else
                    printf("Client Data:%s\n",rec);
            }
            else
            {
                close(connect_fd);
                printf("Do you want to conitnue");
                scanf("%c",&ch);
            }
        }
    }
    close(socket_fd);
}