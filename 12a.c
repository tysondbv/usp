#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        printf("Child Process is Running\n");
        sleep(2);
        printf("Child process is exited....\n");
        exit(0);
    } else {
        printf("Parent process waiting...\n");
        sleep(5);
        wait(NULL);
        printf("Parent process exiting\n");
    }

    return 0;
}
