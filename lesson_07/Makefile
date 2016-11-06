all: sorting stack_test libstack.so
	echo all done

sorting: sorting.c
	gcc sorting.c -o sorting

stack.o: stack.c stack.h
	gcc -fPIC -c stack.c -o stack.o

libstack.a: stack.o
	ar rcs libstack.a stack.o

libstack.so: stack.o
	gcc -shared -o libstack.so stack.o

stack_test: stack_test.c libstack.a
	gcc stack_test.c -o stack_test -L. -lstack

