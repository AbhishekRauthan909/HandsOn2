/*
============================================================================
Name : 15.c
Author :Abhishek Rauthan
Description :  Write a simple program to send some data from parent to the child process.
Date:2 oct 2023
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int fields[2];
    int a=pipe(fields);
    if(a==-1)
    {
        printf("\nRun the program again");
        exit(1);
    }
    int fd=fork();
    if(fd==-1)
    {
        printf("\nCan't create the child process");
        exit(2);
    }
    else if(fd==0)//child process 
    {
        close(fields[1]);//we are closing the write end
        char r[30];
        int bytes_read=read(fields[0],r,sizeof(r));
        if(bytes_read!=0&&bytes_read!=-1)
        {
            r[bytes_read]='\0';
        }
        printf("%s",r);
    }
    else//parent process
    {
        close(fields[0]);//we are closing the read end
        char a[]="Hello Abhishek Rauthan";
        write(fields[1],a,sizeof(a));
    }
}