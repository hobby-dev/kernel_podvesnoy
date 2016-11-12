#include "binary_tree.h"

#include <stdlib.h>
#include <assert.h>

int32_tree * create_int32_tree(const int32_t data)
{
    int32_tree * value = (int32_tree*) malloc(sizeof(int32_tree));

    value->data = data;
    value->left = NULL;
    value->right = NULL;

    return value;
}

void insert(int32_tree ** tree, int32_t data)
{
    if (*tree == NULL)
        *tree = create_int32_tree(data);
    else if (data < (*tree)->data)
        insert(&(*tree)->left, data);
    else
        insert(&(*tree)->right, data);

}
