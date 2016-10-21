#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list* next;
};

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

void add_to_list(struct list * head, int data)
{
    struct list * ned_data = malloc(sizeof(struct list));
    ned_data->data = data;
    ned_data->next = NULL;

    struct list * ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = ned_data;
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

int main()
{
    struct list * test_list = malloc(sizeof(struct list)); 
    test_list->data = 0;
    test_list->next = NULL;
    // could we init it like: *test_list = {...}; ?
    printf("Enter size: ");
    int size;
    scanf("%d", &size);
    add_to_list(test_list, size);
    print_list(test_list);
    clear_list(test_list);
    return 0;
}
