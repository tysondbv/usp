#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){

link("file.txt","hard.txt");
symlink("file.txt","soft.txt");

struct stat fs1;
struct stat fs2;
struct stat fs;

stat("file.txt",&fs);
stat("soft.txt",&fs1);
lstat("hard.txt",&fs2);

printf("Original file size: %ld, inode: %ld\n", fs.st_size, (long)fs.st_ino);
printf("Hard link file size: %ld, inode: %ld\n", fs2.st_size, (long)fs2.st_ino);
printf("Symbolic link file size: %ld, inode: %ld\n", fs1.st_size, (long)fs1.st_ino);

return 0;
}
