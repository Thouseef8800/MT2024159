/**
Name:Q9.c
Author:Thouseef
Description:Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date:18th September 2024
**/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int main() {
    signal(SIGINT,SIG_IGN );
    sleep(5);
    printf("SIGINT is now being ignored.\n");
    signal(SIGINT, SIG_DFL);
    printf("SIGINT is now reset to its default action. Press Ctrl+C again.\n");
    sleep(5);
    return 0;
}
/**Output:
^C^C^C^C^CSIGINT is now being ignored.
SIGINT is now reset to its default action. Press Ctrl+C again.
^C
**/
