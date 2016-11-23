#include <stdio.h>
#include <inttypes.h>
#include "binary_tree.h"

int main()
{
    int32_t data = 0;
    printf("Enter first tree element: \n");
    scanf("%d", &data);
    int32_tree * root = create_int32_tree(data);
    for (int i = 0; i < 10; ++i)
    {
        scanf("%d", &data);
        insert(&root, data);
        print_tree(root);
    }

    return 0;
}
