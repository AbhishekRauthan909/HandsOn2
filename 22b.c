/*
============================================================================
Name : 22b.c
Author :Abhishek Rauthan
Description :Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date:7 oct 2023
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int fd;
    fd=open("twenty_a",O_WRONLY);
    char input[]="Hello";
    write(fd,input,sizeof(input));
    printf("%s",input);
}

