/*
============================================================================
Name : 27a.c
Author :Abhishek Rauthan
Description:Write a program to receive messages from the message queue.
 a. with 0 as a flag
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
    rcvdata.mtype=1;
    int status;
    status=msgrcv(mid,&rcvdata,sizeof(rcvdata),rcvdata.mtype,0);
    if(status==-1)
    {
        printf("There is an error while receiving the message");
    }
    else
    {
        printf("The received data is %d",rcvdata.data);
    }

}