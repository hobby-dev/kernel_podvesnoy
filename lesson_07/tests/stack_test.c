#include <stdio.h>
#include <assert.h>
#include "stack.h"

#define SIZE 7
int main()
{
    int test_data[SIZE] = {6, 4, -656, 34, 33, 1, 0};
    struct stack * stack = create_stack();
    int i = 0;
    for (; i < SIZE; ++i)
    {
        push(stack, test_data[i]);
    }
    for (--i; i > -1; --i)
    {
        printf("%d\n", first(stack));
        assert(pop(stack) == test_data[i]);
    }
    return 0;
}
