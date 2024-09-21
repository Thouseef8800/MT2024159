/**
Name:Q8.c
Author:Thouseef
Description:Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
Date:18th September 2024
**/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigsegv(int sig) {
    printf("Caught signal %d Segmentation Fault\n", sig);
    exit(1);
}

int main() {
    signal(SIGSEGV, handle_sigsegv);

    int *seg = NULL;
    *seg = 8;

    return 0;
}
/**Output:
Caught signal 11 Segmentation Fault
**/
