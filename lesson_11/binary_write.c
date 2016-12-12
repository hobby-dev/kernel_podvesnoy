#include <stdio.h>
#include "person_struct.h"

#define PERSONS_COUNT 3

int main()
{
    int size = PERSONS_COUNT;

    struct person persons[PERSONS_COUNT] = {
        { "Vasya", 23, 4.0 },
        { "Petya", 24, 4.1 },
        { "Kolya", 25, 4.2 }
    };

    FILE * out = fopen("persons.dat", "w");
    if (out != NULL)
    {
        int ret = fwrite(&size, sizeof(size), 1, out);
        if (ret > 0)
        {
            printf("size written\n");
            ret = fwrite(persons, sizeof(struct person), size, out);
            if (ret == size)
                printf("persons written\n");
            else
                perror("fwrite");
        }
        else
            perror("fwrite");
        fclose(out);
    }
    else
        perror("fopen");

    return 0;
}
