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

void handle_sigvtalrm(int sig) {
    printf("Caught SIGVTALRM signal %d (Virtual Timer Triggered)\n", sig);
}

int main() {
    struct itimerval timer;

    signal(SIGVTALRM, handle_sigvtalrm);

    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;

    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1) {
        printf("Program running... Waiting for virtual timer to expire.\n");
        for (volatile int i = 0; i < 10000; i++);
    }

    return 0;
}
/**Output:
Program running... Waiting for virtual timer to expire.
Program running... Waiting for virtual timer to expire.
Program running... Waiting for virtual timer to expire.
Program running... Waiting for virtual timer to expire.
Program running... Waiting for virtual timer to expire.
Program running... Waiting for virtual timer to expire.
Program running... Waiting for virtual timer to expire
**/
