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

void handle_sigfpe(int sig) {
    printf("Caught SIGFPE signal %d (Floating Point Exception)\n", sig);
    exit(1);
}

int main() {
    signal(SIGFPE, handle_sigfpe);

    int x = 1;
    int y = 0;
    int result = x / y;

    printf("Result: %d\n", result);

    return 0;
}
/**Output:
Caught SIGFPE signal 8 (Floating Point Exception)
**/
