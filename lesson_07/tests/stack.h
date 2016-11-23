#pragma once

struct stack_node
{
    // user defined data:
    int data;
    // list
    struct stack_node * prev;
};

struct stack
{
    struct stack_node * top;
    int size;
};

struct stack * create_stack();

void push(struct stack * stack_ptr, int data);

int pop(struct stack * stack_ptr); 

int first(struct stack * stack_ptr); 

void remove_stack(struct stack * stack_ptr); 
