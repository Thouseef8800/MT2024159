/**
Name:Q19d.c
Author:thouseef
Description:mknod system call
Date:19th September 2024
**/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    if (mknod("myfifo2", S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        exit(EXIT_FAILURE);
    }
    printf("FIFO created using mknod system call\n");
    return 0;
}
/**Output:
FIFO created using mknod system call
**/
