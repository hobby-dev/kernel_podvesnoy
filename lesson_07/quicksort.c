#include <stdio.h>
#include <assert.h>
#include <stdint.h>

#define SIZE 7

void swap(int data[], int from, int to)
{
    assert(from != to);
    int temporary = data[from];
    data[from] = data[to];
    data[to] = temporary;
}

void quick_sort(int32_t * data, int size)
{
    // recursion base:
    if (size < 2)
        return;

    int l = 0, r = size-1;
    int m = size/2;

    for (;;)
    {
        while (data[l] < data[m])
        {
            ++l;
        }
        while (data[r] > data[m])
        {
            --r;
        }
        if (l < r) 
        {
            if (data[l] != data[r])
            {
                swap(data, l, r);
                // keep m:
                if (l == m)
                    m = r;
                else if (r == m)
                    m = l;
            }
            else
            {
                // special case for input like: 0, X, X, 0, X, 0, 0
                ++l;
            }
        }
        else
        {
            assert(l == r);
            break;
        }
    }
    quick_sort(data, l);
    quick_sort(data + l, size - l);
}

int main()
{
    int32_t data[SIZE] = { 0 };
    printf("Enter %d elements:\n", SIZE);
    for (int i = 0; i < SIZE; ++i)
    {
        scanf("%d", &data[i]);
    }
    quick_sort(data, SIZE);

    for (int i = 0; i < SIZE; ++i)
    {
        printf("%d, ", data[i]);
    }
    printf("\n");

    return 0;
}
