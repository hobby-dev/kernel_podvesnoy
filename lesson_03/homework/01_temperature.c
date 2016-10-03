#include <stdio.h>
#include <inttypes.h>

void convertFromFahrenheit()
{
    int32_t temperature = 0;
    printf("Please, enter temperature, ℉  "); 
    scanf("%d", &temperature);
    printf("Result %f ℃\n", (temperature - 32)/1.8);
}

void convertFromCelsius()
{
    int32_t temperature = 0;
    printf("Please, enter temperature, ℃  ");
    scanf("%d", &temperature);
    printf("Result %f ℉\n", temperature * 1.8 + 32);
}

int main()
{
    char answer = 0;
    printf("Welcome to Celsius <-> Fahrenheit converter!\n");
    printf("What scale to convert from? (C/f): ");
    scanf("%c", &answer);
    switch(answer)
    {
        case 'F':
        case 'f':
            convertFromFahrenheit();
            break;
        default:
            convertFromCelsius();
            break;
    };

    return 0;
}
