/**
Name:Q22.c
Author:Thouseef
Description:Program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date:20th September 2024**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>

int main() {
    fd_set rfds;
    struct timeval tv;
    char buff[100];

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    int fd = open("myfifo1", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open FIFO");
        exit(EXIT_FAILURE);
    }

    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);

    int retval = select(fd + 1, &rfds, NULL, NULL, &tv);

    if (retval == -1) {
        perror("select()");
        close(fd);
        exit(EXIT_FAILURE);
    } else if (retval == 0) {
        printf("No data is available for reading yet\n");
    } else {
        ssize_t numBytes = read(fd, buff, sizeof(buff) - 1);
        if (numBytes > 0) {
            buff[numBytes] = '\0';
            printf("Data from FIFO: %s\n", buff);
        } else {
            perror("Failed to read data from FIFO");
        }
    }

    close(fd);
    return 0;
}
/**
Output:
**/
