#include <stdio.h>
#include <stdint.h>

int main ()
{
    uint16_t test1 = 1 << 15; 
    uint16_t test2 = test1;
    uint16_t sum = test1 + test2;
    printf(" sum: %u ", sum);
    return 0;

}
