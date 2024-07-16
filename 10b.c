#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1, pid2;
    pid1 = fork();
    if (pid1 == 0)
    {
        // First child process
        printf("First child PID: %d\n", getpid());
        sleep(2); // Simulate some work with sleep
        return 1; // Exit with status 1
    }
    else
    {
        // Parent process
        // Second fork to create the second child process
        pid2 = fork();
        if (pid2 == 0)
        {
            // Second child process
            printf("Second child PID: %d\n", getpid());
            sleep(4); // Simulate some work with sleep
            return 2; // Exit with status 2
        }
        else
        {
            // Parent process
            int status;
            pid_t waited_pid;
            // Use wait() to wait for any child to finish
            waited_pid = wait(&status);
            printf("Waited for any child. PID: %d, Exit Status: %d\n", waited_pid, WEXITSTATUS(status));
            // Use waitpid() to wait for the second child specifically
            waited_pid = waitpid(pid2, &status, 0);
            printf("Waited for second child. PID: %d, Exit Status: %d\n", waited_pid, WEXITSTATUS(status));

            return 0;
        }
    }
}
