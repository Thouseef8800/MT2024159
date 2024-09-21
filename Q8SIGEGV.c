#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigsegv(int sig) {
    printf("Caught signal %d Segmentation Fault\n", sig);
    exit(1);
}

int main() {
    signal(SIGSEGV, handle_sigsegv);

    int *seg = NULL;
    *seg = 8;

    return 0;
}
