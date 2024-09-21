/**
Name:Q13a.c
Author:Thouseef
Description:Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date:18th September 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(){
printf("PID of the process is %d \n",getpid());
for(int i=0;i<30;i++){
printf("Hello\n");
sleep(4);
}
return 0;
}
/**Output:
PID of the process is 18017 
Hello
Hello
**/
