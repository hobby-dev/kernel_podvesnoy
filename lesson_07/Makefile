all: sorting stack_test
	echo all done

sorting: sorting.c
	gcc sorting.c -o sorting

stack.o: stack.c stack.h
	gcc -c stack.c -o stack.o

libstack.a: stack.o
	ar rcs libstack.a stack.o

stack_test: stack_test.c libstack.a
	gcc stack_test.c -o stack_test -L. -lstack

