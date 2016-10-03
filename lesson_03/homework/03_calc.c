#include <stdio.h>
#include <inttypes.h>

int main()
{
    double first = 0.0, second = 0.0, result = 0.0;
    char operator = 0; 
    printf("Welcome to simple calculator!\n");
    printf("Supported operations: +, -, *, /\n");
    scanf("%lf %c %lf", &first, &operator, &second);
    switch(operator)
    {
        case '+':
            result = first + second;
            break;
        case '-':
            result = first - second;
            break;
        case '*':
            result = first * second;
            break;
        case '/':
            result = first / second;
            break;
        default:
            printf("Unsupported operator: %c\n", operator);
            break;

    }
    printf("Result: %f\n", result);
    return 0;   
}
