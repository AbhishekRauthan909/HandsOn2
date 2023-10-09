/*
============================================================================
Name : 32b.c
Author :Abhishek Rauthan
Description:Write a program to implement semaphore to protect any critical section.
b. protect shared memory from concurrent write access
Date:9 oct 2023
============================================================================
*/
#include <sys/ipc.h>   
#include <sys/sem.h>  
#include <sys/types.h> 
#include <sys/shm.h>   
#include <unistd.h>    
#include <stdio.h>
#include<string.h>
int main()
{
    key_t semaphorekey,sharedmemorykey;
    int semid,sharedid;
    int semstatus,shastatus;
    ssize_t shmSize = 20;
    union semun
    {
        int val;
    } semaphore;

    semaphorekey = ftok(".",1234);
    if (semaphorekey == -1)
    {
        perror("Error while computing key!");
        _exit(1);
    }
        semid=semget(semaphorekey, 1, IPC_CREAT | 0744);
        semaphore.val = 1;
        semstatus= semctl(semid, 0, SETVAL, semaphore);
        if (semstatus== -1)
        {
            perror("Error while initializing a binary sempahore!");
            _exit(1);
        }
    sharedmemorykey= ftok(".", 12345);
    if (sharedmemorykey== -1)
    {
        perror("Error while computing key!");
        _exit(0);
    }
    sharedid= shmget(sharedmemorykey, shmSize, IPC_CREAT | 0744); 

    if (sharedid==-1)
    {
        perror("Error while getting Shared Memory!");
        _exit(0);
    }
    char* addr= shmat(sharedid,NULL,0);
    if (*addr== -1)
    {
        perror("Error while attaching address space!");
        _exit(0);
    }
    struct sembuf op;
    op.sem_num = 0;
    op.sem_flg = 0;
    printf("Press enter to lock the critical section!\n");
    getchar();
    op.sem_op = -1;
    shastatus = semop(semid, &op, 1);
    if (shastatus==-1)
    {
        perror("Error while operating on semaphore!");
        _exit(1);
    }
    printf("Start of the critical section!\n");
    char input[]="Hello";
    strcpy(addr,input);
    printf("Press enter to read from the shared memory!\n");
    getchar();
    printf("%s\n",addr);
    printf("Press enter to exit the critical section!\n");
    getchar();
    op.sem_op = 1;
    shastatus= semop(semid, &op, 1);
    printf("unlocked!\n");
}