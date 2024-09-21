/**
Name:Q17dup.c
Author:Thouseef
Description:Write a program to execute ls -l | wc.
a. use dup
Date:20th September 2024
**/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main() {
int fd[2];
pipe(fd);
if (!fork()) {
close(1);
close(fd[0]);
dup(fd[1]);
execlp("ls", "ls", "-l", (char*) NULL);
}
else {
close(0);
close(fd[1]);
dup(fd[0]);
execlp("wc", "wc", (char*) NULL);
}
}
/**Output:
57     506    4463
**/
