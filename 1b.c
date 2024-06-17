#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/wait.h>
int main(){
        int fd = open("file.txt",O_RDONLY);
        int pid = fork();
        char buffer[10];
        if(pid == 0){
                read(fd,buffer,10);
                buffer[10]='\0';
                printf("Child Process %s\n",buffer);
        }
        else{
                wait(NULL);
                read(fd,buffer,10);
                buffer[10] = '\0';
                printf("Parent read: %s\n", buffer);
        }
        close(fd);
        return 0;
}
