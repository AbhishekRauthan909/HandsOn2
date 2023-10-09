/*
============================================================================
Name : 28.c
Author :Abhishek Rauthan
Description: Write a program to change the exiting message queue permission
Date:9 oct 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/msg.h>      
#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
int main()
{
    key_t key;
    struct msqid_ds info;
    key=ftok(".",1);
    int mid;
    mid=msgget(key,IPC_CREAT|0744);
    int status=msgctl(mid,IPC_STAT,&info);
    if(status==-1)
    {
        printf("Run the program again");
        exit(1);
    }
    char character;
    printf("Do you want to change the permission Press Y or y to change the permission\n");
    scanf("%c",&character);
    if(character=='y'||character=='Y')
    {
        info.msg_perm.mode = 0647;
        status=msgctl(mid,IPC_SET,&info);
        if(status==-1)
        {
            printf("Error in setting the permission");
        }
        else
        {
            printf("Permission changes successfully");
        }
    }
    else
    {
        printf("Ok");
    }
}