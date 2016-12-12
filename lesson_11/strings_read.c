#include <stdio.h>

#define N 15

int main()
{
    FILE * test = fopen("readme.md", "r");
    if (test != NULL)
    {
        char buf[N] = {0};
        int counter = 0;

        while (fgets(buf, N, test) != NULL)
        {
            printf("%s", buf);
            ++counter;
        }
        printf("Counted %d strings\n", counter);
        fclose(test);
    }
    else
        perror("fopen");

    return 0;
}
