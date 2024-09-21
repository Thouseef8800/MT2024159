/**
Name:Q19e.c
Author:Thouseef
Description:FIFO created using mknod system call
Date:21th September 2024
**/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    if (mkfifo("myfifo4", 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
    printf("FIFO created using mkfifo library function\n");
    return 0;
}

/**Output:
FIFO created using mkfifo library function
**/
