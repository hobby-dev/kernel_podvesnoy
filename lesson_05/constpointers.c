#include <stdio.h>

int main()
{
    int a = 5; //or int const a = 5;
    //++a; ERROR!
    const int b = 6;
    int const * b_ptr = &a;
    //*b_ptr = 42; ERROR!
    ++b_ptr;
    int * const c_ptr = &a;
    *c_ptr = 42;
    ++c_ptr;
    return 0;
}
