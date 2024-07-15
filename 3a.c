#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>


int main(){
    DIR *dir;
    struct stat fs;
    struct dirent *entry;
    
    dir = opendir(".");
    while((entry = readdir(dir))!=NULL){
        stat(entry->d_name,&fs);
        if(fs.st_size == 0){
            printf("empty files %s :",entry -> d_name);
            remove(entry -> d_name);
        }
    }
    return 0;
}
