#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
    int res = truncate("hello.txt", 50);
    if (res == 0)
        printf("Truncated!\n");
    return 0;
}
