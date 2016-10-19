#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 0;
    printf("Enter size\n");
    scanf("%d", &size);

    // int array[size]; // gcc supports VLA, but not M$ Visual Studio

    int *array = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i)
        scanf("%d", (array + i));

    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += *(array + i);
    }
    printf("Average: %f\n", (double) sum / (double)size);
    free(array);
    return 0;
}
