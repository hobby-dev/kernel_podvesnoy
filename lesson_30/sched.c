#include <stdio.h>

struct process
{
    int priority;
    int time_to_complete;
    int age;
    int total_time_waited;
    int total_time;

    struct process * next;
    struct process * prev;
};

int print_process_list(struct process * head)
{
    return 0;
};

int create_process_list_from_file(const char * filename, struct process * head)
{
    FILE *input_file;
    input_file = fopen(filename, "r");
    if (input_file)
    {
        int ret;
        do {
            int new_process_priority = 0;
            int new_process_complete_time = 0;

            ret = fscanf(input_file, "P:%d;TC:%d\n", &new_process_priority, &new_process_complete_time);
            if (ret)
            {
                printf("priority %d, time to complete: %d\n", new_process_priority, new_process_complete_time);
            }
        } while (ret != EOF);
    }
    else
        perror("Open file");
    return 0;
};

int main()
{
    struct process* all_processes;
    int ret = create_process_list_from_file("all_processes.txt", all_processes);
    if (ret != 0)
        perror("Create process list");

    print_process_list(all_processes);

    return 0;
}
