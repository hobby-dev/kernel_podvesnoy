#include <stdio.h>
#include <getopt.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

static struct option opts[] =
{
    /* Argument styles: no_argument, required_argument, optional_argument */
    {"filename", required_argument,	NULL,	'f'},
    {0,0,0,0}
};

int main(int argc, char * argv[])
{
    struct stat file_stat;
    char * filename = NULL;
    char opt_symb;

    while( (opt_symb = getopt_long(argc, argv, "f:", opts, NULL)) != -1)
    {
        switch(opt_symb)
        {
            case 'f':
                filename = optarg;
                break;
            case '?':
            default:
                printf("Unknown option\n");
                //exit(1)
                break;
        }
    }

    if (filename)
        printf("Entered filename: %s\n", filename);

    int ret = stat(filename, &file_stat);
    if (ret == 0)
    {
        switch(file_stat.st_mode & S_IFMT)
        {
            case S_IFBLK:
                printf("block device\n");
                break;
            case S_IFDIR:
                printf("directory\n");
                break;
            case S_IFREG:
                printf("regular file\n");
                break;
            default:
                printf("Unknown device\n");
                break;
        }
    }
    else
        perror("stat");

    return 0;
}

