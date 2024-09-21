/**
Name:Q3b.c
Author:Thouseef
Description:Write a program to set (any one) system resource limit. Use setrlimit system call.
Date:18th September 2024
**/
#include<sys/resource.h>
#include<sys/time.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
struct rlimit r_limit;
r_limit.rlim_cur = 5;
setrlimit(RLIMIT_CPU,&r_limit);
while(1){
}
return 0;
}
/**Output:
CPU time limit exceeded (core dumped)
**/

