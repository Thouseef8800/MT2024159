/**
Name:Q2.c
Author:Thouseef
Description:Write a program to print the system resource limits. Use getrlimit system call.
Date:18th September 2024
**/
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

void print_limit(int resource, const char* resource_name) {
    struct rlimit limit;
    if (getrlimit(resource, &limit) == 0) {
        printf("%s:\n", resource_name);
        printf("  Soft limit: %ld\n", (long)limit.rlim_cur);
        printf("  Hard limit: %ld\n\n", (long)limit.rlim_max);
    } else {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }
}

int main() {
    print_limit(RLIMIT_CPU, "CPU time");
    print_limit(RLIMIT_FSIZE, "File size");
    print_limit(RLIMIT_DATA, "Data segment size");
    print_limit(RLIMIT_STACK, "Stack size");
    print_limit(RLIMIT_NOFILE, "Number of file descriptors");

    return 0;
}
/**Output:
CPU time:
  Soft limit: -1
  Hard limit: -1

File size:
  Soft limit: -1
  Hard limit: -1

Data segment size:
  Soft limit: -1
  Hard limit: -1

Stack size:
  Soft limit: 8388608
  Hard limit: -1

Number of file descriptors:
  Soft limit: 1024
  Hard limit: 1048576

**/
