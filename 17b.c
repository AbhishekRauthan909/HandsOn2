/*
============================================================================
Name : 17b.c
Author :Abhishek Rauthan
Description :Write a program to execute ls -l | wc.
 b. use dup2
Date:2 oct 2023
============================================================================
*/
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
    int fields[2];
    pipe(fields);
    int fd=fork();
    if(fd==-1)
    {
        printf("\nCant create child run it again");
        exit(1);
    }
    else if(fd==0)
    {
        close(fields[0]);//closing the reading end of the pipe for child
        fields[1]=dup2(fields[1],1);
        execlp("ls","ls","-l",(char*)NULL);
    }
    else
    {
        close(fields[1]);
        fields[0]=dup2(fields[0],0);
        execlp("wc","wc",(char*)NULL);
    }
}