/**
Name:Q10.c
Author:Thouseef
Description:Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINTc. SIGFPE
Date:18th September 2024
**/
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigint(int sig, siginfo_t *info, void *context) {
    printf("\nCaught signal %d (SIGINT). Exiting gracefully...\n", sig);
    exit(0);
}

int main() {
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle_sigint;

    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    while (1) {
        printf("Program running... Press Ctrl+C to test signal handling.\n");
        sleep(2);
    }

    return 0;
}
/**Output:
Program running... Press Ctrl+C to test signal handling.
Program running... Press Ctrl+C to test signal handling.
^C
Caught signal 2 (SIGINT). Exiting gracefully...
**/
