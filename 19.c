/*
============================================================================
Name : 19.c
Author :Abhishek Rauthan
Description :Create a FIFO file by
 a. mknod system call
 b. mkfifo system call
Date:2 oct 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>     
#include <unistd.h>
#include <stdio.h>    
int main()
{
    int a=mkfifo("my_fifo_file",0744);
    if(a==-1)
    {
        printf("\nFile not created");
    }
    else
    {
        printf("\nFifo File created");
    }
    int b=mknod("mynod_fifo",S_IFIFO|0744,0);
    if(b==-1)
    {
        printf("\nFifo file not created using mknod");
    }
    else
    {
        printf("\nFifo file created using mknod");
    }
}