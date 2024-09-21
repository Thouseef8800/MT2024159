/**
Name:Q21b.c
Author:Thouseef
Description:Two programs so that both can communicate by FIFO -Use two way communications.
Date:19th September 2024
**/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main() {
int fd1 = open("myfifo1", O_RDONLY);
int fd2 = open("myfifo2", O_WRONLY);
char buff1[100];
char buff2[100];
printf("Enter the text:");
scanf(" %[^\n]", buff2);
write(fd2, buff2, sizeof(buff2));
read(fd1, buff1, sizeof(buff1));
printf("The text from FIFO file: %s\n", buff1);
}
/**Output:Enter the text:Hello pavan
The text from FIFO file: Hello Thouseef
**/
