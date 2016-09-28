#include <stdio.h>

int main()
{
    int temp = 26;
    
    printf("Input temperature:\n");
    scanf("%d", &temp);

    if (temp > 25)
    {
        printf("Hot!\n");
    }
    else
    {
        if (temp > 20 && temp <= 25)
            printf("Warm!\n");
        else
            printf("Cold!\n");
    }

    return 0;
}
