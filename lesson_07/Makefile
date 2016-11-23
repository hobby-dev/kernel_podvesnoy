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

stack_test: tests/stack_test.c static_stack_lib
	cp libstack.a stack.h tests/
	cd tests && gcc stack_test.c -o stack_test -L. -lstack

binary_tree.o: binary_tree.c binary_tree.h
	cc -fPIC -c binary_tree.c -o binary_tree.o

static_binary_tree_lib: binary_tree.o
	ar rcs libbinary_tree.a binary_tree.o

binary_tree_test: tests/binary_tree_test.c static_binary_tree_lib
	cp libbinary_tree.a binary_tree.h tests/
	cd tests && gcc binary_tree_test.c -o binary_tree_test -L. -lbinary_tree
