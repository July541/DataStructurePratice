#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>
#include <stdbool.h>

#include "stack_base.h"

// Create an empty stack
Stack* create_stack(void);

// Push an item onto the stack
bool push_stack(Stack* stack, void* data_in_ptr);

// Pop item on the top of the stack
void* pop_stack(Stack* stack);

// Retrieves data from the top of the stack without changing the stack
void* stack_top(Stack* stack);

// True if stack empty, else false
bool empty_stack(Stack* stack);

// True if heap full, false if heap has room
bool full_stack(Stack* stack);

// Return number of elements in stack
size_t stack_count(Stack* stack);

// Release all nodes to the heap
Stack* destory_stack(Stack* stack);

#endif // __STACK_H__