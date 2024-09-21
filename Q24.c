/**
Name:Q24.c
Author:Thouseef
Description:Program to create a message queue and print the key and message queue id.
Date:20th September 2024
**/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

struct message_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t msg_key = ftok("msgqueuefile", 65);
    if (msg_key == -1) {
        perror("Failed to generate key");
        exit(EXIT_FAILURE);
    }

    int queue_id = msgget(msg_key, 0666 | IPC_CREAT);
    if (queue_id == -1) {
        perror("Failed to create message queue");
        exit(EXIT_FAILURE);
    }

    printf("Key: %d\n", msg_key);
    printf("Message Queue ID: %d\n", queue_id);

    msgctl(queue_id, IPC_RMID, NULL);
    return 0;
}
/**Output:
Key: 1090921509
Message Queue ID: 0
**/
