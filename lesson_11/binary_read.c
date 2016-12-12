#include <stdio.h>
#include <stdlib.h> // malloc
#include "person_struct.h"


int main()
{
    FILE * in = fopen("persons.dat", "r");
    if (in != NULL)
    {
        int size = 0;

        int ret = fread(&size, sizeof(size), 1, in);
        if (ret == 1)
        {
            printf("Persons count %d\n", size);
            struct person * persons = (struct person *)malloc(sizeof(struct person) * size);
            ret = fread(persons, sizeof(struct person), size, in);
            if (ret == size)
            {
                printf("Persons:\n");

                for (int i = 0; i < size; ++i)
                {
                    struct person * pers = persons + i;
                    printf("Name: %s\n", pers->name);
                    printf("Age: %d\n", pers->age);
                    printf("Average mark: %f\n", pers->average_mark);
                }
            }
            else
                perror("fread");

            free(persons);
        }
        else
            perror("fread");
        fclose(in);
    }
    else
        perror("fopen");



    return 0;
}
