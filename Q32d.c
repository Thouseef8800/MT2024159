/**
Name:Q32d.c
Author:Thouseef
Description:
remove the created semaphore
Date:21th September 2024
**/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t key = ftok("tmp", 'R');
    int semid = semget(key, 2, 0666 | IPC_CREAT);

    semctl(semid, 0, IPC_RMID, 0);
    printf("Semaphore removed.\n");

    return 0;
}
/**
Output:
Semaphore removed.
**/
