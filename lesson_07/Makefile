all: sorting stack_test libstack.so
	echo all done

sorting: sorting.c
	gcc sorting.c -o sorting

quicksort: quicksort.c
	gcc quicksort.c -o quicksort 

stack.o: stack.c stack.h
	gcc -fPIC -c stack.c -o stack.o

static_stack_lib: stack.o
	ar rcs libstack.a stack.o

shared_stack_lib: stack.o
	gcc -shared -o libstack.so stack.o

stack_test: stack_test.c static_stack_lib
	gcc stack_test.c -o stack_test -L. -lstack

