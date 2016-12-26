#include <dirent.h>
#include <stdio.h>
#include <errno.h>

int main()
{
    DIR * this_dir = opendir(".");

    errno = 0;

    struct dirent * dir_entry = NULL;
    while (1)
    {
        if (dir_entry = readdir(this_dir))
        {
            printf("dir entry: %s \n", dir_entry->d_name);
        }
        else if(errno == 0)
        {
            break; //end of directory
        }
        else
        {
            perror("readdir");
        }
    }
    
    return 0;
}
