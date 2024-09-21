/**
Name:Q21.c
Author:Thouseed
Description:Two programs so that both can communicate by FIFO -Use two way communications.
Date:21th September 2024
**/
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main() {
int fd1 = open("myfifo1", O_WRONLY);
int fd2 = open("myfifo2", O_RDONLY);
char buff1[100];
char buff2[100];
printf("Enter the text:");
scanf(" %[^\n]", buff1);
write(fd1, buff1, sizeof(buff1));
read(fd2, buff2, sizeof(buff2));
printf("The text from FIFO file: %s\n", buff2);
}
/**Output:Enter the text:Hello Thouseef
The text from FIFO file: Hello pavan
**/
