#include <stdio.h>

#define N 7

void sort_bubble(int input[], int output[])
{
    // Make a copy of array first:
    for (int i = 0; i < N; ++i)
    {
        output[i] = input[i];
    }

    int current = 0;
    int next = 1;
    while (current < N)
    {
        if (next < N && output[current] > output[next])
        {
            int swap = output[current];
            output[current] = output[next];
            output[next] = swap;
            if (current > 0)
            {
                --current;
                --next;
            }
        } else {
            ++current;
            ++next;
        }
    }
}

int main()
{
    int data[N] = {541, 763, 208, 322, 67, 999, 1};
    int sorted[N];
    sort_bubble(data, sorted);
    printf("Sorted result:\n");
    for (int i = 0; i < N; ++i)
        printf("%d,", sorted[i]);
    return 0;
}
