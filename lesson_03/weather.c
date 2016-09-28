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
