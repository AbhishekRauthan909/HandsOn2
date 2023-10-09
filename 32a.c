/*
============================================================================
Name : 32a.c
Author :Abhishek Rauthan
Description:Write a program to implement semaphore to protect any critical section.
 a. rewrite the ticket number creation program using semaphore
Date:9 oct 2023
============================================================================
*/
#include <sys/ipc.h>  
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
struct tick
{
    int data;
}ticket;
int main()
{
    int fd;
    fd=open("ticket.txt",O_CREAT|O_RDWR,0744);
    key_t key;
    key=ftok(".",32);
    union 
    {
        int value;
    }semaphore;
    int smid=semget(key,1,0);
    if(smid==-1)
    {
        smid=semget(key,1,IPC_CREAT|0744);
        semaphore.value=1;
        int status=semctl(smid,0,SETVAL,semaphore);
        if(status==-1)
        {
          printf("\nThere is an error in initialising the semaphore");
        }
        else
        {
        printf("\nSemaphore initialised successfully");
        }
    }
    struct sembuf buf;
    buf.sem_flg=0;
    buf.sem_num=0;
    printf("Press enter to acquire lock");
    getchar();
    buf.sem_op=-1;
    int opstatus=semop(smid,&buf,1);
    if(opstatus==-1)
    {
        printf("Error");
    }
    int no_of_bytes=read(fd,&ticket,sizeof(ticket));
    if(no_of_bytes==-1)
    {
        printf("There is an error in reading the ticket number");
    }
    else
    {
        ticket.data=ticket.data+1;
        lseek(fd,0,SEEK_SET);
        write(fd,&ticket,sizeof(ticket));
        printf("Your ticker number is %d",ticket.data);
    }
    fflush(stdin);
    printf("Press enter to get out of the lock");
    getchar();
    getchar();
    buf.sem_op=1;
    opstatus=semop(smid,&buf,1);
    if(opstatus==-1)
    {
        printf("Error");
    }
    close(fd);
}