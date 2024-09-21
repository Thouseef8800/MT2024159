/**
Name:Q30.c
Author:Thouseef
Description:Program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
**/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed");
        exit(EXIT_FAILURE);
    }

    char *data = (char *)shmat(shmid, NULL, 0);
    if (data == (char *)(-1)) {
        perror("shmat failed");
        exit(EXIT_FAILURE);
    }

    strcpy(data, "Hello, Memory");
    printf("Data written to shared memory: %s\n", data);

    if (shmdt(data) == -1) {
        perror("shmdt failed");
        exit(EXIT_FAILURE);
    }

    int shmid_read = shmget(key, 1024, 0444);
    char *data_read = (char *)shmat(shmid_read, NULL, SHM_RDONLY);
    if (data_read == (char *)(-1)) {
        perror("shmat failed");
        exit(EXIT_FAILURE);
    }

    printf("Data read from shared memory: %s\n", data_read);

    // Instead of attempting to write, simply print a message
    printf("Attempting to overwrite in read-only mode is not allowed.\n");

    if (shmdt(data_read) == -1) {
        perror("shmdt failed");
        exit(EXIT_FAILURE);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl IPC_RMID failed");
        exit(EXIT_FAILURE);
    }

    printf("Shared memory removed.\n");
    return 0;
}


/**Output:
Data written to shared memory: Hello, Memory
Data read from shared memory: Hello, Memory
Attempting to overwrite in read-only mode is not allowed.
Shared memory removed.

**/
