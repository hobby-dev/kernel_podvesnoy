struct list
{
    int data;
    struct list * next;
};

void print_list(struct list * head);

struct list * create_new_list_elem(int data);

void add_to_list(struct list * head, struct list * new_elem);

void clear_list(struct list * head);


