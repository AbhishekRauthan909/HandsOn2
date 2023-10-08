/*
============================================================================
Name : 21b.c
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
    fd1=open("twenty_a",O_RDONLY);//opening the fifo file in read only mode
    fd2=open("twenty_b",O_WRONLY);//opening this fifo file in write only mode
    char input[]="Hello from b";
    char output[50];
    int a=read(fd1,output,sizeof(output));
    if(a==-1)
    {
        printf("Cant't read from twenty_a");
    }
    close(fd1);
    int b=write(fd2,input,sizeof(input));
    if(b==-1)
    {
        printf("Can't write into twnety_b");
    }
    close(fd2);
    printf("\n%s",output);
}