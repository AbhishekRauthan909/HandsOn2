/*
============================================================================
Name : 23.c
Author :Abhishek Rauthan
Description :Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date:8 oct 2023
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
int main() {
    long maximum; 
    long size;
    maximum = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of files that can be opened within the process: %ld\n", maximum);
    size=pathconf("twenty_a", _PC_PIPE_BUF);
    printf("Maximum size of a pipe (circular buffer): %ld bytes\n",size);
    return 0;
}
