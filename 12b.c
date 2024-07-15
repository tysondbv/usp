#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(){

        int pid;
        pid = fork();
        if(pid == 0)
      {
                setenv("var1","value",1);
                setenv("var2","value",1);

                printf("child process\n");
                printf(" user defined %s\n : ",getenv("var1"));
                printf("User defined %s\n: ",getenv("var2"));
        
                execl("/usr/bin/env", "env", NULL);
        
                printf("User defined var1: %s\n", getenv("var1"));
                printf("User defined var2: %s\n", getenv("var2"));
                exit(0);
        }

        else
        {
                wait(NULL);
                printf("PATH = %s\n",getenv("PATH"));
                printf("HOME = %s\n", getenv("HOME"));
                printf("SHELL = %s\n", getenv("SHELL"));

        }
        return 0;
}
