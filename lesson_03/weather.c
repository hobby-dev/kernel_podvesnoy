#include <stdio.h>

int get_temperature()
{
    int temperature = 0;
    printf("Input temperature:\n");
    scanf("%d", &temperature);
    return temperature;
}

void print_temperature(int temperature)
{
    if (temperature > 25)
    {
        printf("Hot!\n");
    }
    else
        switch(temperature)
        {
            case 25:
                printf("warm\n");
                break;
            case 24:
                printf("good\n");
                break;
            case 23:
                printf("still good\n");
                break;
            default:
                printf("cold\n");
                break;
        }
}

int main()
{
    print_temperature(get_temperature());
    return 0;
}

