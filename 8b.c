#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(){
int pid = fork();
if(pid<0){
printf("error");
}
else if(pid == 0){
printf("child process execution started ids are  (PID: %d, PPID: %d)\n",getpid(),getppid());
const char * fp = "file.txt";
if(access(fp,F_OK)==0){
printf("child process can access file1.txt");
}
if (access(fp, R_OK) == 0) {
 printf("Child Process: File %s is readable.\n", fp);}
}
else{
wait(NULL);
printf("Parent Process (PID: %d): Child process (PID: %d) exited.\n", getpid(), pid);
}
return 0;
}
