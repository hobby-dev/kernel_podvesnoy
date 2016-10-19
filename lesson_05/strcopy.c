#include <stdio.h>

#define MAX 100

void copy_str1(char str_dest[], const char str_src[])
{
    int i = 0;
    
    for (; str_src[i] != '\0'; ++i)
        str_dest[i] = str_src[i];

    str_dest[i] = str_src[i];
}

int main()
{
    char str1[MAX] = "Hello, world!";
    char str2[MAX] = "";
    copy_str1(str2, str1);
    printf("%s\n", str1);
    printf("%s\n", str2);
    return 0;
}
