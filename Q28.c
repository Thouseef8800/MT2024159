/**
Name:Q28.c
Author:Thouseef
Description:Program to change the exiting message queue permission. (use msqid_ds structure)
Date:20th September 2024
**/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;
    struct msqid_ds msgqueue_info;

    key = ftok("msgqueuefile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        exit(EXIT_FAILURE);
    }

    if (msgctl(msgid, IPC_STAT, &msgqueue_info) == -1) {
        perror("msgctl IPC_STAT failed");
        exit(EXIT_FAILURE);
    }

    printf("Current permissions: %o\n", msgqueue_info.msg_perm.mode);

    msgqueue_info.msg_perm.mode = 0660;

    if (msgctl(msgid, IPC_SET, &msgqueue_info) == -1) {
        perror("msgctl IPC_SET failed");
        exit(EXIT_FAILURE);
    }

    if (msgctl(msgid, IPC_STAT, &msgqueue_info) == -1) {
        perror("msgctl IPC_STAT failed");
        exit(EXIT_FAILURE);
    }
    printf("Updated permissions: %o\n", msgqueue_info.msg_perm.mode);

    return 0;
}
/**Output:
Current permissions: 666
Updated permissions: 660
**/
