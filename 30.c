/*
============================================================================
Name : 30.c
Author :Abhishek Rauthan
Description:Write a program to create a shared memory.
 a. write some data to the shared memory
 b. attach with O_RDONLY and check whether you are able to overwrite.
 c. detach the shared memory
 d. remove the shared memory
Date:9 oct 2023
============================================================================
*/
#include<sys/types.h>
#include<sys/shm.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    key_t key;
    key=ftok(".",3);
    int sid;
    ssize_t segsize=10;
    sid=shmget(key,segsize,IPC_CREAT|0744);
    if(sid==-1)
    {
        printf("Segmemt not created");
        exit(1);
    }
    else
    {
        printf("Segment created");
    }
    char *addr=shmat(sid,NULL,0);
    if(*addr==-1)
    {
        printf("Segment not attached");
        exit(1);
    }
    char input[]="hello";
    strcpy(addr,input);
    shmdt(addr);//detaching
    addr=shmat(sid,NULL,SHM_RDONLY);//attaching the memory for reading purpose
    if(*addr==-1)
    {
        printf("Can't attach");
        exit(1);
    }
    else
    {
        printf("data:%s",addr);
    }
    //strcpy(addr,input);//it should give us error
    shmdt(addr);//detaching it
    int dstatus=shmctl(sid,IPC_RMID,NULL);
    if(dstatus==-1)
    {
        printf("Segment not deleted successfully");
    }
    else
    {
        printf("\nSegment deleted successfully");
    }
}