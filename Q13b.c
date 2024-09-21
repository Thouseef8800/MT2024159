/**
Name:Q13a.c
Author:Thouseef
Description:Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date:18th September 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Enter the pid");
        return 1;
    }

    pid_t pid = atoi(argv[1]);

    if (kill(pid, SIGSTOP) == -1) {
        perror("kill");
        return 1;
    }

    printf("Sent SIGSTOP to process %d\n", pid);
    return 0;
}
/**Output:
Enter the pid 18104
sent SIGSTOP to process 18104
**/
