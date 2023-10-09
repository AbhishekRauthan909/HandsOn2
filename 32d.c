/*
============================================================================
Name : 32d.c
Author :Abhishek Rauthan
Description:Write a program to implement semaphore to protect any critical section.
 d. remove the created semaphore 
Date:9 oct 2023
============================================================================
*/
#include<sys/types.h> 
#include<sys/ipc.h>   
#include<sys/sem.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    key_t key;
    int semid;
    int semstatus;
    key= ftok(".",123);
    if (key==-1)
    {
        printf("Error while generating the key");
        exit(1);
    }
    semid=semget(key,1,IPC_CREAT|0744);
    if (semid==-1)
    {
        printf("There is an error while creating the semaphore");
        exit(1);
    }
    else
    {
        printf("Semaphore created successfully");
    }
    char input;
    printf("Do you want to delete the semaphore\n");
    scanf("%c",&input);
    if(input=='Y'||input=='y')
    {
        semstatus=semctl(semid,0,IPC_RMID);
        if(semstatus==-1)
        {
            printf("There is an error while deleting the semaphore");
        }
        else
        {
            printf("Semaphore deleted successfully");
        }
    }
}