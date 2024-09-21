/**
Name:Q20b.c
Author:Thouseef
Description:Two programs so that both can communicate by FIFO -Use one way communication.
Date:21th September 2024
**/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
int fd2=open("myfifo2",O_WRONLY);
char buff[100];
printf("Enter the data into the fifo:");
scanf(" %[^\n]",buff);
write(fd2,buff,sizeof(buff));
return 0;
}
/**
Output:Enter the data into the fifo:Hello World
**/
