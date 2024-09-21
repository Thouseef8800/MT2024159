/**
Name:Q17dup2.c
Author:Thouseef
Description:Write a program to execute ls -l | wc.
 use dup2
Date:20th September 2024
**/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main() {
int fd[2];
pipe(fd);
if (!fork()) {
close(fd[0]);
dup2(fd[1],1);
execlp("ls", "ls", "-l", (char*) NULL);
}
else {
close(fd[1]);
dup2(fd[0],0);
execlp("wc", "wc", (char*) NULL);
}

}
/**Output:
61     542    4786
**/


