#include "binary_tree.h"

#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

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

#define LINE_WIDTH 80
#define NODE_WIDTH 4
void print_tree_line(const int32_tree * tree, const int line)
{
    if (tree == NULL)
        return;
    const int num_nodes = (int)pow(2, line);
    const int output_width = NODE_WIDTH * num_nodes;
    const int skip_width = (LINE_WIDTH - output_width) / 2;
    for (int i = 0; i < skip_width; ++i)
        printf(" ");
    const int has_next_line = 0;
    for (int i = 0; i < num_nodes; ++i)
        printf("\n", );

}

void print_tree(const int32_tree * tree)
{
    print_tree_line(tree, 0);
}
