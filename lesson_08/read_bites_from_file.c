#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
    int fd = open("hello.txt", O_RDONLY);

    if (fd > 0)
    {
        char symbol;
        int res;
        do
        {
            res = read(fd, &symbol, sizeof(symbol));
            printf("%c", symbol);
        }
        while (res > 0);
        close(fd);
    }
    else
    {
        perror("Error opening file");
    }

    return 0;
}

