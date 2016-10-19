#include <stdio.h>

void foo()
{
    static int counter = 0;
    printf("counter = %d\n", counter);
    ++counter;
}

int main()
{

    for (int i = 0; i < 10; ++i)
    {
        foo();
    }
    return 0;
}
