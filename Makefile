.PHONY: clean

all: stack

stack.o: ./stack/stack.c
	gcc -o $@ -c $<

stack: ./Utils/test_stack.c stack.o
	gcc $@.o $< -o ds_stack
	rm $@.o

clean:
	rm ds_stack