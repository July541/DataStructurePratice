#ifndef __STACK_BASE_H__
#define __STACK_BASE_H__

#include <stddef.h>

typedef struct node {
    void* data_ptr;
    struct node* link;
} Stack_node;

typedef struct {
    size_t count;
    Stack_node* top;
} Stack;

#endif // __STACK_BASE_H__