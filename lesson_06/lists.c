#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

void print_list(struct list * head)
{
    struct list * ptr = head;
    int counter = 0;
    
    while (ptr != NULL)
    {
        printf("list[%d] = %d\n", counter, ptr->data);
        ptr = ptr->next;
        ++counter;
    }
}

struct list * create_new_list_elem(int data)
{
    struct list * res_ptr = NULL;
    res_ptr = (struct list *)malloc(sizeof(struct list));
    res_ptr->data = data;
    res_ptr->next = NULL;
    return res_ptr;
}

void add_to_list(struct list * head, struct list * new_elem)
{
    struct list * ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = new_elem;
}

void clear_list(struct list * head)
{
    struct list * ptr = head;
    while (ptr->next != NULL)
    {
        struct list * ptr_to_delete = ptr;
        ptr = ptr->next;
        free(ptr_to_delete);
    }
}

