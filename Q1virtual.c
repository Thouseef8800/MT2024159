/**
Name:Q1b.c
Author:Thouseef
Description:Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
Date:18th September 2024
**/
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void virtual_timer_handler(int vir) {
    printf("Virtual Timer expired! Signal received: %d\n", vir);
}

int main() {
    struct itimerval timer;
    signal(SIGVTALRM, virtual_timer_handler);
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;
    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("setitimer");
        exit(EXIT_FAILURE);
    }
    while (1) {
    }

    return 0;
}
/**Output:
Virtual Timer expired! Signal received: 26
**/
