#include <stdio.h>

int main()
{
    FILE *file_ptr = fopen("readme.md", "r");
    if (file_ptr != NULL)
    {
        int counter = 0;
        char symb;
        while ( (symb = fgetc(file_ptr)) != EOF)
        {
            printf("%c", symb);
            ++counter;
        }
        printf("Couned %d symbols\n", counter);
        fclose(file_ptr);
    }
    else
        perror("fopen");

    return 0;
}
