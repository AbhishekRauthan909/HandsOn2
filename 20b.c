/*
============================================================================
Name : 20b.c
Author :Abhishek Rauthan
Description :Write two programs so that both can communicate by FIFO.
Use one way communication.
Date:2 oct 2023
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
     int fd;//this is for file descriptor
     fd=open("my_fifo_file",O_RDONLY);//opening the fifo file in read only mode
     char data[15];
     read(fd,data,sizeof(data));
    printf("hello");
}
