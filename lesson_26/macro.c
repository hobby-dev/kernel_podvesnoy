#include <stdio.h>

#define N 100
int a[N];

#define double(x) (2*(x))
#define max(a,b) ((a) > (b) ? (a) : (b))
#define double_increment(a,b) do {\
    a++;\
    b++;\
} while (0)

#define print_type(type_name) {\
    type_name test_variable;\
    printf(#type_name "'s size of %ld\n", sizeof(test_variable));\
}

#define make_type(type,name) {\
    struct type ## name { \
        type value; \
    }; \
    printf(#type #name " size = %ld\n", sizeof(struct type ## name));\
}

int main()
{
    int x = 3;
    int y = 1;
    printf("double x = %d\n", double(x + 1));
    printf("max(x,y) = %d\n", max(x,y));
    printf("max(++x,y) = %d\n", max(++x,y));

    int j=1,k=1;
    if (0)
        double_increment(j,k);
    else
        printf("not incremented\n");
    printf("j, k %d, %d\n", j, k);

    print_type(int);

    make_type(double, wow);

    return 0;
}

