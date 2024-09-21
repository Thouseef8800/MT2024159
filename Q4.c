/**
Name:Q4.c
Author:Thouseef
Description:Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date:18th September 2024
**/
#include<sys/time.h>
#include <stdio.h>
#include <unistd.h>

unsigned long long rdtsc()
{
 unsigned long long dst;
  __asm__ __volatile__("rdtsc":"=A"(dst));
 return dst;
}


int main()
{
 long long int start,end;
 pid_t ppid;
 start = rdtsc();
 for (int i = 0; i < 100; i++) {
        ppid = getppid(); 
    }
 end = rdtsc();
 printf("Time taken for 100 getppid() calls: %llu cycles\n", (end - start));
 return 0;
}
/**Output:
ime taken for 100 getppid() calls: 127496 cycles
**/
