#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
struct 
{
    int a;
}ticket;
int main()
{
    int fd;
    fd=open("ticket.txt",O_CREAT|O_RDWR,0766);
    if(fd==-1)
    {
        printf("file not created");
    }
    else
    {
        printf("file created");
    }
    ticket.a=1;
    write(fd,&ticket,sizeof(ticket));
}