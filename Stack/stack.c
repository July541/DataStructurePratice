#include "stack.h"

Stack* create_stack(void) {
    Stack* stack;

    stack = (Stack*)malloc(sizeof(Stack));
    if (stack) {
        stack->top = NULL;
        stack->count = 0;
    }

    return stack;
}

bool push_stack(Stack* stack, void* data_in_ptr) {
    Stack_node* new_node;

    new_node = (Stack_node*)malloc(sizeof(Stack_node));
    if (!new_node) {
        return false;
    }

    new_node->data_ptr = data_in_ptr;

    new_node->link = stack->top;
    stack->top = new_node;

    stack->count++;

    return true;
}

void* pop_stack(Stack* stack) {
    void* data_out_ptr;

    Stack_node* tmp;

    if (stack->count == 0)
        data_out_ptr = NULL;
    else {
        data_out_ptr = stack->top->data_ptr;

        tmp = stack->top;
        stack->top = stack->top->link;

        free(tmp);
        stack->count--;
    }
    return data_out_ptr;
}

void* stack_top(Stack* stack) {
    if (stack->count == 0)
        return NULL;
    return stack->top->data_ptr;
}

bool empty_stack(Stack* stack) {
    return stack->count == 0;
}

bool full_stack(Stack* stack) {
    Stack_node* tmp;

    tmp = (Stack_node*)malloc(sizeof(*(stack->top)));
    if (tmp) {
        free(tmp);
        return false;
    }

    return true;
}

size_t stack_count(Stack* stack) {
    return stack->count;
}

Stack* destory_stack(Stack* stack) {
    Stack_node* tmp;

    if (stack) {
        while(stack->top != NULL) {
            tmp = stack->top;
            stack->top = stack->top->link;

            free(tmp->data_ptr);
            free(tmp);
        }

        free(stack);
    }
    return NULL;
}