#include <stdio.h>

#define N 5

int main()
{
    char str[N] = "bbbbb";
    char str2[N] = "asdfq";    
    for (int i = 0; i < N; ++i)
    {
        scanf("%c", &str[i]);
    }
    printf("%s\n", str);
    printf("%s\n", str2);
    return 0;
}

