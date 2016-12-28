#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // exit()
#include <sys/types.h> // PID
#include <sys/wait.h>

int main()
{
    pid_t first_pid, second_pid;
    int pipefd[2] = {0};

    if (pipe(pipefd) < 0)
    {
        perror("pipe");
        exit(1);
    }

    first_pid = fork();

    if (first_pid == 0)
    {
        dup2(pipefd[1], 1); // write to pipe instead stdout
        close(pipefd[0]);
        close(pipefd[1]);

        execl("numbers", "numbers", NULL);
    }
    else
    {



    }
    return 0;
}
