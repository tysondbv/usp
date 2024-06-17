#include <stdio.h>
#include <fcntl.h>

void printFlags(int fd) {
    int flags = fcntl(fd, F_GETFL);
    printf("File flags for descriptor %d:\n", fd);
    printf("O_APPEND: %s\n", (flags & O_APPEND) ? "Yes" : "No");
    printf("O_NONBLOCK: %s\n", (flags & O_NONBLOCK) ? "Yes" : "No");
    printf("O_SYNC: %s\n", (flags & O_SYNC) ? "Yes" : "No");
    // Add more flags as needed
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file descriptor>\n", argv[0]);
        return 1;
    }

    int fd = atoi(argv[1]);
    printFlags(fd);

    return 0;
}
