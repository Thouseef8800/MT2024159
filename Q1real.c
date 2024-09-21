/**
Name:Q1a.c
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

void handle_alarm(int real
) {
    printf("Timer expired!\n");
}

int main() {
    struct itimerval timer;
    signal(SIGALRM, handle_alarm);
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("setitimer");
        exit(EXIT_FAILURE);
    }
    while (1) {
    }

    return 0;
}
/**Output:
TIMER EXPIRED
**/
