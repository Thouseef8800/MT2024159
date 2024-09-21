/**
Name:Q10.c
Author:Thouseef
Description:Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINTc. SIGFPE
Date:18th September 2024
**/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigfpe(int sig, siginfo_t *info, void *context) {
    printf("Caught signal %d (SIGFPE - Arithmetic Error). Exiting gracefully...\n", sig);
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle_sigfpe;

    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    int x = 0;
    int result = 42 / x;

    printf("Result: %d\n", result);

    return 0;
}
/**Output:
Caught signal 8 (SIGFPE - Arithmetic Error). Exiting gracefully...
**/
