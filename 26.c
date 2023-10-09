/*
============================================================================
Name : 26.c
Author :Abhishek Rauthan
Description:Write a program to send messages to the message queue.
Date:9 oct 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <stdio.h>     
#include <unistd.h>  
#include <errno.h> 
int main()
{
    key_t key;
    key=ftok(".",7);
    int mid=msgget(key,IPC_CREAT|0744);
    struct mymsg
    {
        long mtype;
        int data;
    }msg;
    msg.mtype=1;
    msg.data=2023;
    int status;
    status=msgsnd(mid,&msg,sizeof(msg),0);
    if(status==0)
    {
        printf("Message sent succefully");
    }
    else
    {
        printf("Message not sent successfully");
    }
}
