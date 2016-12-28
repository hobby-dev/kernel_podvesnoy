#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    // if we want to write to other file:
    // fopen() + fprintf() + fclose() or open() + write() + close()
    // but there is 3rd way: dup()!
    int out_fd = creat("numbers_out.txt", 0644);
    close(1);
    //int ret = dup(out_fd);
    int ret = dup2(out_fd, 1);
    if (ret != 1)
        perror("dup");
    close(out_fd);

    for (int i = 0; i < 10; ++i)
        printf("i = %d\n", i);

    return 0;
}
