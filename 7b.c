#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int src = open(argv[1], O_RDONLY);
    int dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    char buffer[4096];
    ssize_t bytesRead;
    while ((bytesRead = read(src, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytesRead);
    }

    close(src);
    close(dest);
    return 0;
}
