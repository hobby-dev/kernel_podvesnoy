#include <stdio.h>

#define SIZE 5 

int find_minimal_index(const int * data, const int size, int current_minimal_index)
{
    for (int i = current_minimal_index; i < size; ++i)
    {
        if (data[i] < data[current_minimal_index])
            current_minimal_index = i;
    }
    return current_minimal_index;
}

void swap(int data[], int from, int to)
{
    if (from != to)
    {
        int temporary = data[from];
        data[from] = data[to];
        data[to] = temporary;
    }
}

void sort(int data[], int size)
{
    int first_unsorted_index = 0;
    const int last_index = size - 1;
    // loop invariant: there is always at least 'first_unsorted_index' sorted elements in data[]
    while (first_unsorted_index < last_index)
    {
        int current_minimal_index = find_minimal_index(data, size, first_unsorted_index);
        swap(data, current_minimal_index, first_unsorted_index);
        ++first_unsorted_index;
    }
}

int main()
{
    int data[SIZE] = { 0 };
    printf("Enter %d elements:\n", SIZE);
    for (int i = 0; i < SIZE; ++i)
    {
        scanf("%d", &data[i]);
    }
    sort(data, SIZE);

    for (int i = 0; i < SIZE; ++i)
    {
        printf("%d, ", data[i]);
    }
    printf("\n");
    return 0;
}
