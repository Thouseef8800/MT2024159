/**
Name:Q25.c
Author:Thouseef
Description:program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date:20th September 2024
**/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>
#include <time.h>

int main() {
    key_t msg_key = ftok("msgqueuefile", 65);

    if (msg_key == -1) {
        perror("Failed to generate key");
        exit(EXIT_FAILURE);
    }

    int queue_id = msgget(msg_key, 0666 | IPC_CREAT);
    if (queue_id == -1) {
        perror("Failed to access or create message queue");
        exit(EXIT_FAILURE);
    }

    struct msqid_ds msg_info;

    if (msgctl(queue_id, IPC_STAT, &msg_info) == -1) {
        perror("Failed to get message queue information");
        exit(EXIT_FAILURE);
    }

    printf("Access Permissions: %o\n", msg_info.msg_perm.mode);
    printf("UID: %d\n", msg_info.msg_perm.uid);
    printf("GID: %d\n", msg_info.msg_perm.gid);
    printf("Time of Last Message Sent: %s", ctime(&msg_info.msg_stime));
    printf("Time of Last Message Received: %s", ctime(&msg_info.msg_rtime));
    printf("Time of Last Change: %s", ctime(&msg_info.msg_ctime));
    printf("Size of the Queue: %lu bytes\n", msg_info.__msg_cbytes);
    printf("Number of Messages in the Queue: %lu\n", msg_info.msg_qnum);
    printf("Maximum Number of Bytes Allowed: %lu\n", msg_info.msg_qbytes);
    printf("PID of Last Message Sent: %d\n", msg_info.msg_lspid);
    printf("PID of Last Message Received: %d\n", msg_info.msg_lrpid);

    return 0;
}

/**
Access Permissions: 666
UID: 1000
GID: 1000
Time of Last Message Sent: Thu Jan  1 05:30:00 1970
Time of Last Message Received: Thu Jan  1 05:30:00 1970
Time of Last Change: Sat Sep 21 12:19:38 2024
Size of the Queue: 0 bytes
Number of Messages in the Queue: 0
Maximum Number of Bytes Allowed: 16384
PID of Last Message Sent: 0
PID of Last Message Received: 0
**/
