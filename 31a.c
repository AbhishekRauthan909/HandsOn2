/*
============================================================================
Name : 31a.c
Author :Abhishek Rauthan
Description:Write a program to create a semaphore and initialize value to the semaphore.
 a. create a binary semaphore
Date:9 oct 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    key_t key;
    key=ftok(".",4);
    int semid;
    union semaphore
    {
        int value;
    }sema;
    semid=semget(key,1,IPC_CREAT|0744);
    if(semid==-1)
    {
        printf("There is an error while creating the semaphore");
    }
    else
    {
        printf("The semaphore created successfully");
    }
    sema.value=1;//for binary semaphore and 1 indicate this is an unlocked state
    int status=semctl(semid,0,SETVAL,sema);
    if(status==-1)
    {
        printf("\nThere is an error in initialising the semaphore");
    }
    else
    {
        printf("\nSemaphore initialised successfully");
    }
}