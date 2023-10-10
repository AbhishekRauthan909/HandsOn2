/*
============================================================================
Name :34client.c
Author:Abhishek Rauthan
Description:4. Write a program to create a concurrent server.
 b.use pthread
Date:10 oct 2023
============================================================================
*/
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/ip.h> 
#include <stdio.h>  
#include <unistd.h>
#include <pthread.h>
#include<stdlib.h>
void check(int *fd)
{

    ssize_t rb,wb;
    char send[]="Hello this side server";
    wb = write(*fd,send,sizeof(send));
    if (wb==-1)
        printf("There is an error while writing");
    else
        printf("Data successfully sent to client");
        char rcv[80];
    rb=read(*fd,rcv,sizeof(rcv));
    if (rb==-1)
       printf("There is an error while reading");
    else
        printf("Data:%s",rcv);
    close(*fd);
}

int main()
{
    int socket_fd,connect_fd;
    struct sockaddr_in addr, client;
    pthread_t threadID;
    socket_fd=socket(AF_INET,SOCK_STREAM, 0);
    if (socket_fd==-1)
    {
        printf("There is an error while creating the socket");
    }
    printf("Server side:Socket created successfully");
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    int bstatus=bind(socket_fd,(struct sockaddr *)&addr,sizeof(addr));
    if (bstatus==-1)
    {
        printf("There is an error while binding socket to address");
        exit(1);
    }
    printf("socket binded to address successfully\n");
    int lstatus=listen(socket_fd,2);
    if (lstatus==-1)
    {
        printf("there is some problem in listening");
        exit(1);
    }
    printf("Server now listening\n");
    while(1)
    {
        int csize=(int)sizeof(client);
        connect_fd=accept(socket_fd,(struct sockaddr *)&client,&csize);
        if (connect_fd== -1)
            printf("There is an error while connecting");
        else
        {   
            if (pthread_create(&threadID, NULL, (void *)check, &connect_fd))
                printf("There is an error while creating the thread");
        }
    }
    close(socket_fd);
}