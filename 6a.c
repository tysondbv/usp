#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
        int fd = open("5a.txt",O_RDWR);
        char buffer[5];
        read(fd,buffer,5);
        buffer[5] = '\0';
        lseek(fd,0,SEEK_END);
        int fd1 =0;
        dup2(fd,fd1);
        write(fd,buffer,5);
}
