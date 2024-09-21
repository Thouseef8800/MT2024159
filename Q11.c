/**
Name:Q11.c
Author:Thouseef
Description:Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date:18th September 2024
**/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    struct sigaction sa_ignore, sa_default;

    sa_ignore.sa_handler = SIG_IGN;
    sigemptyset(&sa_ignore.sa_mask);
    sa_ignore.sa_flags = 0;

    if (sigaction(SIGINT, &sa_ignore, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("SIGINT is now being ignored. Press Ctrl+C, but nothing will happen for 5 seconds.\n");
    sleep(5);

    sa_default.sa_handler = SIG_DFL;
    sigemptyset(&sa_default.sa_mask);
    sa_default.sa_flags = 0;

    if (sigaction(SIGINT, &sa_default, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("SIGINT is now reset to its default action. Press Ctrl+C to terminate the program.\n");
    sleep(5);

    return 0;
}
/**Output:
SIGINT is now being ignored. Press Ctrl+C, but nothing will happen for 5 seconds.
^CSIGINT is now reset to its default action. Press Ctrl+C to terminate the program.
^C
**/
