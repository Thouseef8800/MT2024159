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
#include <sys/time.h>
#include <unistd.h>

void handle_sigprof(int sig) {
    printf("Caught SIGPROF signal %d (Profiling Timer Triggered)\n", sig);
}

int main() {
    struct itimerval timer;

    signal(SIGPROF, handle_sigprof);

    timer.it_value.tv_sec = 3;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    while (1) {
        printf("Program running... Waiting for profiling timer to expire.\n");
        for (volatile int i = 0; i < 100000000; i++);
    }

    return 0;
}

/**Output:
rogram running... Waiting for profiling timer to expire.
Program running... Waiting for profiling timer to expire.
Program running... Waiting for profiling timer to expire.
Program running... Waiting for profiling timer to expire.
Caught SIGPROF signal 27 (Profiling Timer Triggered)
Program running... Waiting for profiling timer to expire.
Program running... Waiting for profiling t
**/
