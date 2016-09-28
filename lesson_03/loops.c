#include <stdio.h>

int main()
{
    int counter = 0;
    int sum = 0, current = 0;

    /*while (counter < 5)
    {
        printf("Enter number: ");
        scanf("%d", &current);
        sum += current;
        ++counter;
    }*/
    for (counter; counter < 5; ++counter)
    {
        printf("Enter number: ");
        scanf("%d", &current);
        sum += current;
    }
    printf("Average: %f\n", (double)sum / (double)counter);

    for (int i = 0, j = 10; i != j; ++i, --j)
        printf("i = %d, j = %d\n", i, j);

}
