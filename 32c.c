/*
============================================================================
Name : 32c.c
Author :Abhishek Rauthan
Description:Write a program to implement semaphore to protect any critical section.
c. protect multiple pseudo resources ( may be two) using counting semaphore
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
#include<stdlib.h>
struct ticket
{
    int val;
}ti;
int main()
{
    key_t key;
    int fd,semid;
    ssize_t readBytes;
    off_t lseekOffset;      
    fd=open("ticket.txt", O_RDONLY);
    if (fd==-1)
    {
        printf("There is an error in opening the file");
        exit(1);
    }
    union semun
    {
        int val;           
    } semaphore;
    key=ftok(".", 1321);
    if (key==-1)
    {
        printf("There is an error while generating the key");
        exit(1);
    }
        semid=semget(key,1,IPC_CREAT|0744);
        semaphore.val = 2;
        int status=semctl(semid,0,SETVAL,semaphore);
        if (status==-1)
        {
            printf("There is an error while setting the value of semaphore");
        }
    struct sembuf op;
    op.sem_num = 0;
    op.sem_flg = IPC_NOWAIT;
    printf("Press enter to obtain lock for the critical section!\n");
    getchar();
    op.sem_op = -1;
    int opstatus= semop(semid,&op,1);
    if (opstatus==-1)
    {
        printf("There is an error while operating on semaphore");
        exit(1);
    }
    int rb= read(fd,&ti,sizeof(ti));
    if (rb==-1)
    {
        printf("There is an error while reading the file");
        exit(1);
    }
    else
        printf("\nData: %d", ti.val);
    printf("\nPress enter key to exit critical section!\n");
    getchar();
    op.sem_op =1;
    opstatus=semop(semid,&op,1);
    if (opstatus == -1)
    {
        printf("Error while operating on semaphore!");
        exit(1);
    }
    close(fd);
}