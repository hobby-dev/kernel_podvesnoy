#include <stdio.h>

int main()
{
    int counter = 0;
    int sum = 0, current = 0;

    while (counter < 5)
    {
        printf("Enter number: ");
        scanf("%d", &current);
        sum += current;
        ++counter;
    }
    printf("Average: %f\n", (double)sum / (double)counter);
}
