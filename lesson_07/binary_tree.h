#pragma once
#include <inttypes.h>

typedef struct int32_binary_tree int32_tree;

struct int32_binary_tree
{
    int32_t data;
    int32_tree * left;
    int32_tree * right;
};

int32_tree * create_int32_tree(const int32_t data);

void insert(int32_tree ** tree, int32_t data);

