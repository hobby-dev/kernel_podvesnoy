#include <stdio.h>
#include "globals_foo.h"

int main()
{
    printf("foo = %d\n", foo);
    inc_foo();
    printf("foo = %d\n", foo);
    return 0;;
}
