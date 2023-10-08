/*
============================================================================
Name : 25.c
Author :Abhishek Rauthan
Description :Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
 a. access permission
 b. uid, gid
 c. time of last message sent and received
 d. time of last change in the message queue
 d. size of the queue
 f. number of messages in the queue
 g. maximum number of bytes allowed
 h. pid of the msgsnd and msgrcv
Date:9 oct 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/msg.h>      
#include <stdio.h>
#include <unistd.h>
int main()
{
    key_t key;
    struct msqid_ds info;
    key=ftok(".",1);
    int mid;
    mid=msgget(key,IPC_CREAT|0744);
    int status=msgctl(mid,IPC_STAT,&info);
     printf("Access Permission: %od\n",info.msg_perm.mode);
    printf("UID: %d\n",info.msg_perm.uid);
    printf("GID: %d\n",info.msg_perm.gid);
    printf("Time of last message sent: %ld\n",info.msg_stime);
    printf("Time of last message received: %ld\n",info.msg_rtime);
    printf("Size of queue: %ld\n",info.msg_cbytes);
    printf("Number of messages in the queue: %ld\n",info.msg_qnum);
    printf("Maximum number of bytes allowed in the queue: %ld\n",info.msg_qbytes);
    printf("PID of last sent message: %d\n",info.msg_lspid);
    printf("PID of last received message: %d\n",info.msg_lrpid);
}