#include <stdio.h>
#include "lists.h"

int main()
{
    int size = 0;
    printf("Enter size: ");
    scanf("%d", &size);
    struct list * head = NULL;

    for (int i = 0; i < size; ++i)
    {
        int data = 0;
        printf("Enter data: ");
        scanf("%d", &data);
        struct list * new_elem = create_new_list_elem(data);
        if (head == NULL)
            head = new_elem;
        else
            add_to_list(head, new_elem);

    }
    print_list(head);
    clear_list(head);
    return 0;
}
