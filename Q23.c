/**
Name:Q23.c
Author:Thouseef
Description:Program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 20th September 2024
**/
#include <stdio.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define  _GNU_SOURCE
int main() {
    struct rlimit rlim;
    int pipefd[2];
    long pipe_size;
    if (getrlimit(RLIMIT_NOFILE, &rlim) == 0) {
        printf("Maximum number of files that can be opened: %ld\n", rlim.rlim_cur);
    } else {
        perror("getrlimit");
    }
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }
    pipe_size = fcntl(pipefd[0],F_GETPIPE_SZ);
    if (pipe_size == -1) {
        perror("fcntl");
        close(pipefd[0]);
        close(pipefd[1]);
        return 1;
    }

    printf("Size of the pipe buffer: %ld bytes\n", pipe_size);
    close(pipefd[0]);
    close(pipefd[1]);
    return 0;
}
/**
Output:
Max open files: 1024
Pipe size: 4096 bytes
**/
