/*
============================================================================
Name : 22a.c
Author :Abhishek Rauthan
Description :Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date:7 oct 2023
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
int main()
{
    fd_set fds;
    struct timeval t;
    t.tv_sec=10;
    int fd=open("twenty_a",O_RDONLY|O_NONBLOCK);
    FD_ZERO(&fds);
    FD_SET(fd,&fds);
    if(!select(fd+1,&fds,NULL,NULL,&t))
    {
        printf("\nData is not available yet");
    }
    else
    {
        printf("Another file write into the fifo file so data is available now");
        char output[50];
        read(fd,output,sizeof(output));
        printf("%s",output);
    }
}
