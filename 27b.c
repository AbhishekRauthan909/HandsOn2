/*
============================================================================
Name : 27b.c
Author :Abhishek Rauthan
Description:Write a program to receive messages from the message queue.
 b.with IPC_NOWAIT as a flag
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
    key=ftok(".",7);
    mid=msgget(key,IPC_CREAT|0744);
    struct rcvmsg
    {
        long mtype;
        int data;   
    }rcvdata;
    rcvdata.mtype=10;
    int status;
    status=msgrcv(mid,&rcvdata,sizeof(rcvdata),rcvdata.mtype,IPC_NOWAIT);
    if(status==-1)
    {
        printf("There is an error while receiving the message");
    }
    else
    {
        printf("The received data is %d",rcvdata.data);
    }

}