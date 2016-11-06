#include <stdlib.h>
#include "stack.h"

struct stack * create_stack()
{
    struct stack * ret = (struct stack*) malloc(sizeof(struct stack));
    ret->top = NULL;
    ret->size = 0;
    return ret;
}

void push(struct stack * stack_ptr, int data)
{
    struct stack_node * new_node = (struct stack_node*) malloc(sizeof(struct stack_node));
    new_node->prev = stack_ptr->top;
    new_node->data = data;
    stack_ptr->top = new_node;
    stack_ptr->size++;
}

int pop(struct stack * stack_ptr)
{
    struct stack_node * ptr_to_delete = stack_ptr->top;
    stack_ptr->top = stack_ptr->top->prev;
    int ret = ptr_to_delete->data;
    free(ptr_to_delete);
    return ret;
}

int first(struct stack * stack_ptr)
{
    return stack_ptr->top->data;
}

void remove_stack(struct stack * stack_ptr)
{
    while(stack_ptr->top != NULL)
    {
        struct stack_node * ptr_to_delete = stack_ptr->top;
        stack_ptr->top = stack_ptr->top->prev;
        free(ptr_to_delete);
    }
    free(stack_ptr);
}
