#include <stdio.h>
#include <unistd.h> // open & close
#include <fcntl.h> // O_* flags
#include <errno.h>

#include <string.h> // strlen()

int main()
{
    int fd = open("hello.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd > 0)
    {
        char out[100] = "Hello, world!\n";
        int out_len = strlen(out);
        int written_bytes = write(fd, out, out_len);
        if (written_bytes == out_len)
        {
            printf("Success!\n");
            return 0;
        }
        close(fd);
    }
    perror("Error: ");

    return 0;
}
