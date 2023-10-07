/*
============================================================================
Name : 17a.c
Author :Abhishek Rauthan
Description :Write a program to execute ls -l | wc.
 a. use dup
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
        close(1);//closing STDOUT
        close(fields[0]);//closing the reading end of the pipe for child
        fields[1]=dup(fields[1]);
        execlp("ls","ls","-l",(char*)NULL);
    }
    else
    {
        close(0);
        close(fields[1]);
        fields[0]=dup(fields[0]);
        execlp("wc","wc",(char*)NULL);
    }
}