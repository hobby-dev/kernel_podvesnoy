#include <stdio.h>
#include <unistd.h> //pipe()
#include <stdlib.h> //exit()

int main()
{

    int pipefd[2] = {0};

    if (pipe(pipefd) < 0)
    {
        perror("pipe");
        exit(1);
    }

    FILE * write_ptr = fdopen(pipefd[1], "w");
    fprintf(write_ptr, "Hello_world\n");
    fflush(write_ptr);

    char read_str[255] = {0};
    FILE * read_ptr = fdopen(pipefd[0], "r");
    fscanf(read_ptr, "%s", read_str);

    printf("Pipe read: %s\n", read_str);

    return 0;
}
