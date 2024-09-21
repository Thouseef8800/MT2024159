/**
Name:Q16.c
Author:Thouseef
Description:Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date:18th September 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 100

int main() {
    int pipe1[2];
    int pipe2[2];
    pid_t pid;

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Pipe failed");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        close(pipe1[0]);
        close(pipe2[1]);

        int number;
        for (int i = 1; i <= 5; i++) {
            printf("Parent sending: %d\n", i);
            write(pipe1[1], &i, sizeof(i));
            int square;
            read(pipe2[0], &square, sizeof(square));
            printf("Child returned square: %d\n", square);
        }

        close(pipe1[1]);
        close(pipe2[0]);
    } else {
        close(pipe1[1]);
        close(pipe2[0]);

        int number;
        while (read(pipe1[0], &number, sizeof(number)) > 0) {
            printf("Child received: %d\n", number);
            int square = number * number;
            write(pipe2[1], &square, sizeof(square));
        }

        close(pipe1[0]);
        close(pipe2[1]);
   }

    return 0;
}
/**Output:
Parent sending: 1
Child received: 1
Child returned square: 1
Parent sending: 2
Child received: 2
Child returned square: 4
Parent sending: 3
Child received: 3
Child returned square: 9
Parent sending: 4
Child received: 4
Child returned square: 16
Parent sending: 5
Child received: 5
Child returned square: 25
**/
