#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(){
        int fd = open("file.txt",O_RDONLY);
        char buffer[21];

        // first 20 char
        int size = read(fd,buffer,20);
        buffer[size]='\0';
        printf("Fisr 20 char :%s\n",buffer);
        
        // seek 10 bytes dis 20 bytes
        lseek(fd,10,SEEK_SET);
        size = read(fd,buffer,20);
        buffer[size]='\0';
        printf("seek to 10th byte from the beginning and display 20 characters from there is : %s\n",buffer);

        // seek 10 bytes ahead from the current file offset and display 20 characters
        lseek(fd, 10, SEEK_CUR);
        size = read(fd,buffer,20);
        buffer[size]='\0';
        printf("Characters after 10 bytes ahead: %s\n", buffer);

        struct stat fs;
        stat("file.txt",&fs);
        printf("file size is :%ld\n",fs.st_size);
        return 0;
}
