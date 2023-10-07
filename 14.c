/*
============================================================================
Name : 14.c
Author :Abhishek Rauthan
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date:2 oct 2023
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int fields[2];
    //read end file descriptor will be at fields[0]
    //write end file descriptor will be at fields[1]
    int a=pipe(fields);
    if(a==-1)
    {
        printf("\nRun it again");
        exit(1);
    }
    char get[30];
    char data[]="Bengaluru";
    write(fields[1],data,sizeof(data));
    int bytes_read=read(fields[0],get,sizeof(get));
    printf("%s",get);
}