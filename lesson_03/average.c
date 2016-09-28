#include <stdio.h>

int main()
{
    int counter = 0;
    int sum = 0, num = 0;

    while(num >= 0)
    {
        printf("Enter positive number (negative to quit): ");
        scanf("%d", &num);
        if (num < 0)
            continue;

        sum += num;
        ++counter;
    }
    printf("Average: %f\n", (double)sum/(double)counter);
}
