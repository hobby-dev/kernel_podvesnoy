#include <stdio.h>
#include <stdint.h>

int main()
{
    uint8_t t1;
    uint16_t t2;
    uint32_t t3;
    uint64_t t4;
    unsigned int i1;
    unsigned short i2;
    unsigned char i3;
    unsigned long i4;

    printf("size of uint8_t = %ld\n", sizeof(t1));
    printf("size of uint16_t = %ld\n", sizeof(t2));
    printf("size of uint32_t = %ld\n", sizeof(t3));
    printf("size of uint64_t = %ld\n", sizeof(t4));

    printf("size of unsigned int = %ld\n", sizeof(i1));
    printf("size of unsigned short = %ld\n", sizeof(i2));
    printf("size of unsigned char = %ld\n", sizeof(i3));
    printf("size of unsigned long = %ld\n", sizeof(i4));

    uint8_t test1 = 255;
    int8_t test2 = 255;

    printf("test1 value = %u\n", test1);
    printf("test2 value = %d\n", test2);

    return 0;
}
