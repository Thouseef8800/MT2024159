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

void handle_sigalrm(int sig) {
    printf("Caught SIGALRM signal %d (Timer Triggered)\n", sig);
}

int main() {
    struct itimerval timer;

    signal(SIGALRM, handle_sigalrm);

    timer.it_value.tv_sec = 3;
    timer.it_value.tv_usec = 0;

    timer.it_interval.tv_sec = 2;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        printf("Program running... Waiting for timer to expire.\n");
        sleep(1);
    }

    return 0;
}
/**Output:
Program running... Waiting for timer to expire.
Program running... Waiting for timer to expire.
Program running... Waiting for timer to expire.
Caught SIGALRM signal 14 (Timer Triggered)
Program running... Waiting for timer to expire.
Program running... Waiting for timer to expire.
Caught SIGALRM signal 14 (Timer Triggered)
Program running... Waiting for timer to expire.

**/
