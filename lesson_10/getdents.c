#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <errno.h>

#define BUF_SIZE 1024

struct linux_direntry
{
    long d_ino;
    off_t d_off;
    unsigned short d_reclen;
    char d_name[BUF_SIZE];
};

int main()
{
    int fd = open("/home/user", O_RDONLY | O_DIRECTORY);
    if (fd > 0)
    {
        struct linux_direntry dir_entry;
        int ret;
        do
        {
            ret = syscall(SYS_getdents, fd, &dir_entry, sizeof(struct linux_direntry));
            if (ret > 0)
            {
                printf("Directory entry: %s\n", dir_entry.d_name);
                lseek(fd, dir_entry.d_off, SEEK_SET); //TODO: check for error
            }
        } 
        while (ret > 0);
        if (ret < 0)
            perror("syscall");
        close(fd);
        printf("Readed\n");
    }
    return 0;
}

