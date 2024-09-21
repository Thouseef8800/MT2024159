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
#include<unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigint(int sig) {
    printf("Caught signal %d (Interrupt Signal)\n", sig);
    exit(0);
}

int main() {
    signal(SIGINT, handle_sigint);

    while (1) {
        printf("Program running... Press Ctrl+C to stop.\n");
        sleep(1);
    }

    return 0;
}
/**Output:
Program running... Press Ctrl+C to stop.
Program running... Press Ctrl+C to stop.
Program running... Press Ctrl+C to stop.
Program running... Press Ctrl+C to stop.
^CCaught signal 2 (Interrupt Signal)
**/
