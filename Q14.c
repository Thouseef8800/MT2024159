/**
Name:Q14.c
Author:Thouseef
Description:Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date:18th September 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
int i, j, fd[2];
char buf[80];
i = pipe(fd);
printf("i=%d\n", i);
j = write(fd[1], "Hello\n", 7);
read(fd[0], buf, j);
printf("From pipe: %s\n", buf);
return 0;
}
/**Output:
i=0
From pipe: Hello

**/

