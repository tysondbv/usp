#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
        int fd = open("file.txt",O_RDONLY);
        int size = lseek(fd,0,SEEK_END);
        char ch;
        while(size--){
                lseek(fd,size,SEEK_SET);
                read(fd,&ch,1);
                putchar(ch);
        }
        printf("\n");
        close(fd);
        return 0;
}
