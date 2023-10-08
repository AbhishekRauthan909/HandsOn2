/*
============================================================================
Name : 24.c
Author :Abhishek Rauthan
Description :Write a program to create a message queue and print the key and message queue id.
Date:9 oct 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/msg.h>      
#include <stdio.h>
#include <unistd.h>
int main()
{
    key_t key;
    key=ftok(".",1);
    int mid;
    mid=msgget(key,IPC_CREAT|IPC_EXCL|0744);
    printf("\nkey:%d",key);
    printf("\n%d",mid);
}    

