/**
Name:Q18.c
Author:Thouseef
Description:Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date:20th September 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
int fd1[2], fd2[2];
pipe(fd1);
pipe(fd2);
if (!fork()) {
dup2(fd1[1], 1);
close(fd1[0]);
close(fd2[0]);
close(fd2[1]);
execlp("ls", "ls", "-Rl", (char*) NULL);
}
else {
if (!fork()) {
dup2(fd2[1], 1);
dup2(fd1[0], 0);
close(fd1[1]);
close(fd2[0]);
execlp("grep", "grep", "^d", (char*) NULL);
}
else {
dup2(fd2[0], 0);
close(fd2[1]);
close(fd1[0]);
close(fd1[1]);
execlp("wc", "wc", (char*) NULL);
}
}
}
/**Output:
 0       0       0
**/
