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
#include <unistd.h>

void handle_sigalrm(int sig) {
    printf("Caught SIGALRM signal %d (Alarm Triggered)\n", sig);
}

int main() {
    signal(SIGALRM, handle_sigalrm);

    printf("Setting an alarm for 5 seconds...\n");
    alarm(5);

    while (1) {
        printf("Program running... Waiting for alarm.\n");
        sleep(1);
    }

    return 0;
}
/**Output:
Setting an alarm for 5 seconds...
Program running... Waiting for alarm.
Program running... Waiting for alarm.
Program running... Waiting for alarm.
Program running... Waiting for alarm.
Program running... Waiting for alarm.
Caught SIGALRM signal 14 (Alarm Triggered)
Program running... Waiting for alarm.
Program running... Waiting for alarm.
Program running... Waiting for alarm.
Program running... Waiting for alarm.
^C

**/
