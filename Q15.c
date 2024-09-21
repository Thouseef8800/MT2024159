/**
Name:Q15.c
Author:Thouseef
Description:Write a simple program to send some data from parent to the child process
Date:18th September 2024
**/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main() {
char buff[80];
int fd[2];
pipe(fd);
if (fork()) {
close(fd[0]);
printf("Enter message to the child: ");
scanf(" %[^\n]", buff);
write(fd[1], buff, sizeof(buff));
}
else {
close(fd[1]);
read(fd[0], buff, sizeof(buff));
printf("Message from parent: %s\n", buff);
}
wait(0);
}
/**Output:
Enter message to the child: huiiii
Message from parent: huiiii
**/
