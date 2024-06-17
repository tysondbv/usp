#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle_sigint(int sig) {
    printf("Caught SIGINT\n");
    signal(SIGINT, SIG_DFL);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_sigint;
    sigaction(SIGINT, &sa, NULL);

    while (1) {
        printf("Running...\n");
        sleep(1);
    }

    return 0;
}
