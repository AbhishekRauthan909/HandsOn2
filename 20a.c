/*
============================================================================
Name : 20a.c
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
    char *file_name="my_fifo_file";
    fd=open(file_name,O_WRONLY);//opening the fifo file in write only mode
    char data[]="Hello";
    write(fd,data,sizeof(data));
    return 0;
}
