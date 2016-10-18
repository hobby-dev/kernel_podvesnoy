#include <stdio.h>

#define MAX_SIZE 256

int symb_count(char input[])
{
    int count = 0;
    while(input[count] != '\0')
        ++count;

    return count;
}

int main()
{
    char str[MAX_SIZE];
    scanf("%s", &str[0]);
    printf("Characters count: %d\n", symb_count(str));
    return 0;
}
