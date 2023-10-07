/*
============================================================================
Name : 18.c
Author :Abhishek Rauthan
Description :Write a program to find out total number of directories on the pwd.
 execute ls -l | grep ^d | wc ? Use only dup2.
Date:2 oct 2023
============================================================================
*/
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
    int fields1[2],fields2[2];
    pipe(fields1);
    pipe(fields2);
    int fd=fork();
    if(fd==-1)
    {
        printf("Can't create the child run it again");
        exit(1);
    }
    else if(fd==0)
    {
        dup2(fields1[1],1);
        close(fields1[0]);
        close(fields2[0]);
        close(fields2[1]);
        execlp("ls","ls","-l",(char*)NULL);
    }
    else
    {
        if(!fork())
        {
            dup2(fields2[1],1);
            dup2(fields1[0],0);
            close(fields1[1]);
            close(fields2[0]);
            execlp("grep","grep","^d",(char*)NULL);
        }
        else
        {
            dup2(fields2[0],0);
            close(fields2[1]);
            close(fields1[0]);
            close(fields1[1]);
            execlp("wc","wc",(char*)NULL);
        }
    }
}