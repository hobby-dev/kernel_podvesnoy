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
        second_pid = fork();
        if (second_pid == 0)
        {
            dup2(pipefd[0], 0); // read from pipe instead stdin
            close(pipefd[0]);
            close(pipefd[1]);

            execlp("cat", "cat", NULL); //exec with path
        }
        else
        {
            close(pipefd[0]);
            close(pipefd[1]);

            pid_t ret_pid;
            int status;

            while ((ret_pid = wait(&status)) > 0)
            {
                if (ret_pid == first_pid)
                    printf("p1 finish\n");
                if (ret_pid == second_pid)
                    printf("p2 finish\n");
            }
        }
    }
    return 0;
}
