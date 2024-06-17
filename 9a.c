#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
int main(){
        mode_t old_mask = umask(0);
        int fd = open("file1.txt",O_CREAT,0666);
        close(fd);
        chmod("file1.txt",0644);
        struct stat fs;
        stat("file1.txt",&fs);
        printf("File permissions: %o\n", fs.st_mode & 0777);
        umask(old_mask);
        return 0;
}
