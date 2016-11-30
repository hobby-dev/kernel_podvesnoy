#include <stdio.h>
#include <unistd.h>

int main (int argc, char * argv[])
{
    char option_symb = 0;
    
    while( (option_symb = getopt(argc, argv, "ab:c")) != -1)
    {
        switch(option_symb)
        {

            case 'a':
                printf("-a is set\n");
                break;
            case 'b':
                printf("-b is set with arg = %s\n", optarg);
                break;
            case 'c':
                printf("-c is set\n");
                break;
            case '?':
            default:
                printf("Unknown option.\n");
                break;
        }
    }

    return 0;
}
