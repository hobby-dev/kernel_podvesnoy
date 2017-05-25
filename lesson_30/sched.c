#include <stdio.h>
#include <malloc.h>

struct process
{
    int id;
    int priority;
    int time_to_complete;
    int age;
    // statistics:
    int total_time_waited;
    int total_time;
    // list:
    struct process * next;
};

int print_process_list(struct process * head)
{
    while(head != NULL)
    {
        //printf("P: %d; TC: %d\n", head->priority, head->time_to_complete);
        printf("id: %d, total_time: %d, total_time_waited: %d\n", head->id, head->total_time, head->total_time_waited);
        head = head->next;
    }
    return 0;
};

int create_process_list_from_file(const char * filename, struct process ** head)
{
    FILE *input_file;
    input_file = fopen(filename, "r");
    if (input_file)
    {
        int ret;
        int id = 0;
        do {
            int new_process_priority = 0;
            int new_process_complete_time = 0;

            ret = fscanf(input_file, "P:%d;TC:%d\n", &new_process_priority, &new_process_complete_time);
            if (ret != EOF)
            {
                struct process * current = (struct process*)malloc(sizeof(struct process));
                current->id = id;
                current->priority = new_process_priority;
                current->time_to_complete = new_process_complete_time;
                current->next = NULL;
                *head = current;
                head = &current->next;
            }
            ++id;
        } while (ret != EOF);
    }
    else
        perror("Open file");
    return 0;
};

void schedule(struct process ** head, struct process ** completed)
{
    struct process * first = *head;
    first->total_time += 1;

    struct process * last = *head;
    while(last->next != NULL)
    {
        last = last->next;
        last->age += 1;
        last->total_time_waited += 1;
        last->total_time += 1;
    }

    first->age = 0;
    first->time_to_complete -= 1;

    if (first->time_to_complete == 0)
    {
        *head = first->next;
        first->next = *completed;
        *completed = first;
    }
    else if (first != last)
    {
        *head = first->next;
        last->next = first;
        first->next = NULL;
    }

};

int main()
{
    struct process * completed_head = NULL;
    struct process * active_head = NULL;

    int ret = create_process_list_from_file("all_processes.txt", &active_head);
    if (ret != 0)
        perror("Create process list");

    while (active_head != NULL)
    {
        schedule(&active_head, &completed_head);
    }
    print_process_list(completed_head);

    return 0;
};
