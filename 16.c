/*
============================================================================
Name : 16.c
Author :Abhishek Rauthan
Description :Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date:2 oct 2023
============================================================================
*/
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
    int fields1[2];
    int fields2[2];
    //we are creating two pipes
    pipe(fields1);//pipe1
    pipe(fields2);//pipe2
    int fd=fork();
    if(fd==-1)
    {
        printf("\nCan't create the child process ");
        exit(1);
    }
    else if(fd==0)
    {
        close(fields1[1]);//close write end of the first pipe for child 
        close(fields2[0]);//close read end of the second pipe for child
        char send[]="Hello I am child and this is my message";
        write(fields2[1],send,sizeof(send));
        char recieve[50];
        int d=read(fields1[0],recieve,sizeof(recieve));
        if(d!=0&&d!=-1)
        {
            recieve[d]='\0';
        }
        printf("\n%s",recieve);
    }
    else
    {
        close(fields1[0]);//close read end of the first pipe for parent
        close(fields2[1]);//close write end of the second pipe for parent
        char recieve[50];
        int d=read(fields2[0],recieve,sizeof(recieve));
        if(d!=0&&d!=-1)
        {
            recieve[d]='\0';
        }
        printf("\n%s",recieve);
        char send[]="Hello I am parent and this is my message";
        write(fields1[1],send,sizeof(send));
    }
}