#include <stdio.h>

#define DIMENSION 5

void print_sum(int vector1[], int vector2[])
{
    printf("Sum of two vectors is:\n");
    for (int i = 0; i < DIMENSION; ++i)
    {
        printf("%d ", vector1[i] + vector2[i]);
    }
}

int main()
{
    printf("Welcome to vector addition program!\n" \
           "Expected dimension is: %d\n" \
           "Please, enter first vector:\n", DIMENSION);

    int vector1[DIMENSION];
    int vector2[DIMENSION];

    for (int i = 0; i < DIMENSION; ++i)
    {
        scanf("%d", &vector1[i]);
    }
    printf("Please, enter second vector:\n");

    for (int i = 0; i < DIMENSION; ++i)
    {
        scanf("%d", &vector2[i]);
    }
    print_sum(vector1, vector2);
    return 0;
}
