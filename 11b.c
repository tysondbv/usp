#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  pid_t pid;
  int status;
  char num[10], num[20];

  // Create a child process
  pid = fork();

  if (pid < 0)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if (pid == 0)
  {
    // Child process
    execlp("./add", "add", "10", "20", NULL);
    perror("execlp");
    exit(EXIT_FAILURE);
  }
  else
  {
    // Parent process
    wait(&status);
    printf("Child process completed.\n");
  }

  return 0;
}
