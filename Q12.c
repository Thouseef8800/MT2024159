/**
Name:Q12.c
Author:Thouseef
Description:Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date:18th September 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("Child : Sending SIGKILL to parent process PID: %d\n", getppid());
        kill(getppid(), SIGKILL);
        printf("Child : Parent has been killed. I am now an orphan\n");
        sleep(10);

        printf("Child : Exiting after being orphaned\n");
    } else {
        printf("Parent process: My child process has PID %d.\n", pid);
        sleep(5);
        printf("Parent process: Exiting.\n");
    }

    return 0;
}
/**Output:
Parent process: My child process has PID 17953.
Child : Sending SIGKILL to parent process PID: 17952
Child : Parent has been killed. I am now an orphan
Killed

**/
