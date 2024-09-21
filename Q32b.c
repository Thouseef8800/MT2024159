/**
Name:Q32b.c
Author:Thouseef
Description:
protect shared memory from concurrent write access
Date:21th September 2024
**/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    key_t shm_key = ftok("tmp", 'S');
    key_t sem_key = ftok("tmp", 'P');
    int shmid = shmget(shm_key, SHM_SIZE, 0666 | IPC_CREAT);
    int semid = semget(sem_key, 1, 0666 | IPC_CREAT);
    struct sembuf p = {0, -1, SEM_UNDO};
    struct sembuf v = {0, 1, SEM_UNDO};

    semctl(semid, 0, SETVAL, 1);
    char *data = (char *)shmat(shmid, NULL, 0);

    semop(semid, &p, 1);
    strncpy(data, "Shared memory content", SHM_SIZE);
    printf("Written to the  shared memory: %s\n", data);
    semop(semid, &v, 1);

    shmdt(data);
    return 0;
}
/**Output:
Written to the  shared memory: Shared memory content
**/
