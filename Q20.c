/**
Name:Q20.c
Author:Thouseef
Description:Two programs so that both can communicate by FIFO -Use one way communication.
Date:21th September 2024
**/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd2 = open("myfifo2", O_RDONLY);
    char buff[100];

    read(fd2, buff, sizeof(buff));
    printf("Received data: %s\n", buff);

    close(fd2);
    return 0;
}
/**
Output:Received data: Hello World
**/
