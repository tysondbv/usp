#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(){
  DIR *dir;
  struct dirent *entry;
  struct stat fs;
  dir = opendir(".");
  while((entry=readdir(dir))!=NULL){
    stat(entry->d_name,&fs);
    if(fs.st_size==0){
    printf("empty files are :%s",entry->d_name);
    remove(entry->d_name);
    }
  }
return 0;
}
