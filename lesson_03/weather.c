#include <stdio.h>

int main()
{
    int temp = 26;
    
    printf("Input temperature:\n");
    scanf("%d", &temp);

//    temp > 0 ? printf("Above zero\n") : printf("Below zero\n");
    printf("Temperature is %s\n", temp > 0 ? "above zero" : "below zero");

    if (temp > 25)
    {
        printf("Hot!\n");
    }
    else
        switch(temp)
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
    return 0;
}
