#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int fd = creat("hello.txt", 0644);
    if (fd > 0)
    {
        off_t res = lseek(fd, 100, SEEK_END);
        if (res > 0)
        {
            char str[100] = "Hello!";
            int written_bytes = write(fd, str, strlen(str));
            if (written_bytes > 0)
                printf("Success!!!");
        }
        close(fd);
    }
    return 0;
}

