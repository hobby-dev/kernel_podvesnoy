#include <stdio.h>

#define MAX 100

typedef int Age;

typedef struct
{
    char name[MAX];
    Age age;
} Student; // !

void print_student(Student stud)
{
    printf("name : %s\n", stud.name);
    printf("age: %d\n", stud.age);
}

void print_all_students(Student students[], int count)
{
    for (int i = 0; i < count; ++i)
        print_student(students[i]);
}

void print_all_students2(const Student * students, int count)
{
    for (int i = 0; i < count; ++i)
        print_student(*(students + i));
}

int main()
{

    Student students[MAX] = { {.name = "Ivan", .age = 20 }, \
                   { .name = "Alex", .age = 30 } };

    print_all_students2(students, 2);

    return 0;
}
