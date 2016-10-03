#include <stdio.h>
#include <inttypes.h>

int main ()
{
    int64_t deposit = 0;
    float rate = 0.0;
    uint32_t years = 0;
    double result = 0.0;
    printf("Welcome to interest calculator!\n");
    printf("Please, enter deposit amount: ");
    scanf("%ld", &deposit);
    printf("Please, enter interest rate(%%): ");
    scanf("%f", &rate);
    rate /= 100;
    printf("Please, enter duration ");
    scanf("%u", &years);
    // init accumulator:
    result = deposit;
    // loop invariant: result holds savings after i years:
    for (uint8_t i = 0; i < years; ++i)
    {
        result += result * rate;
    }
    printf("Resulting sum: %f, interst: %f\n", result, result - deposit);
    return 0;
}
