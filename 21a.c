/*
============================================================================
Name : 21a.c
Author :Abhishek Rauthan
Description :Write two programs so that both can communicate by FIFO -Use two way communications.
Date:7 oct 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int fd1,fd2;
    fd1=open("twenty_a",O_WRONLY);//opening the first fifo file in write only mode
    fd2=open("twenty_b",O_RDONLY);//opening this fifo file in read only mode
    char input[]="Hello from a";
    char output[50];
    int a=write(fd1,input,sizeof(input));
    if (a==-1)
    {
        printf("Can't write into twenty_a");
    }
    close(fd1);
    int b=read(fd2,output,sizeof(output));
    if(b==-1)
    {
        printf("Can't read from twenty_b");
    }
    close(fd2);
    printf("%s",output);
}