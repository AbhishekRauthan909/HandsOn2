/*
============================================================================
Name : 29.c
Author :Abhishek Rauthan
Description:Write a program to remove the message queue.
Date:9 oct 2023
============================================================================
*/
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
    key_t key;
    int mid;
    key=ftok(".",2);
    mid=msgget(key,IPC_CREAT|0744);
    int status;
    status=msgctl(mid,IPC_RMID,NULL);
    if(status==-1)
    {
        printf("There is an error while removing the message queue");
    }
    else
    {
        printf("Message queue remove successfully");
    }
}