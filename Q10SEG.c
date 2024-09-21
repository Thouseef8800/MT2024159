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

void handle_sigsegv(int sig, siginfo_t *info, void *context) {
    printf("Caught signal %d (Segmentation Fault), Address: %p\n", sig, info->si_addr);
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle_sigsegv;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    int *p = NULL;
    *p = 42;

    return 0;
}
/**Output:
Caught signal 11 (Segmentation Fault), Address: (nil)
**/
