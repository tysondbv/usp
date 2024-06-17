#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    execl("/bin/sh","sh","-c","ls -l",(char *)0);
    return 0;
}
