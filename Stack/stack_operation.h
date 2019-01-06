#ifndef __STACK_OPERATION_H__
#define __STACK_OPERATION_H__

#include <stdio.h>

#include "stack.h"

/* Helper function */
bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int priority(char c) {
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

void convert_decimal_to_binary() {
    unsigned int num = 59;

    int *digit;
    Stack* stack;

    printf("Decimal: %ud\n", num);

    stack = create_stack();

    while (num > 0) {
        digit = (int*)malloc(sizeof(int));
        *digit = num % 2;
        push_stack(stack, digit);
        num /= 2;
    }

    printf("Binary: ");

    while (!empty_stack(stack)) {
        digit = (int*)pop_stack(stack);
        printf("%1d", *digit);
        free(digit);
    }

    printf("\n");
    destory_stack(stack);
}

void convert_infix_to_postfix_and_evaluation() {
    char *infix = "(8+7)*9+60/3-2"; // result: 153
    char postfix[50] = { 0 };
    char token;
    char* data_ptr;
    int i = 0;

    Stack *stack;

    stack = create_stack();

    printf("Infix formula: %s\n", infix);

    while(*infix != 0) {
        token = *infix;
        if (token == '(') {
            data_ptr = (char*)malloc(sizeof(char));
            *data_ptr = token;
            push_stack(stack, data_ptr);
        }
        else if (token == ')') {
            data_ptr = (char *)pop_stack(stack);
            while(*data_ptr != '(') {
                postfix[i++] = *data_ptr;
                free(data_ptr);
                data_ptr = (char *)pop_stack(stack);
            }
            free(data_ptr);
        }
        else if (is_operator(token)) {
            data_ptr = (char*)stack_top(stack);
            while (!empty_stack(stack) && priority(token) <= priority(*data_ptr)) {
                data_ptr = (char*)pop_stack(stack);
                postfix[i++] = *data_ptr;
                free(data_ptr);
                data_ptr = (char*)pop_stack(stack); // memory leak
            }

            data_ptr = (char*)malloc(sizeof(char));
            *data_ptr = token;
            push_stack(stack, data_ptr);
        }
        else {
            postfix[i++] = token;
        }
        infix++;
    }

    while (!empty_stack(stack)) {
        data_ptr = (char*)pop_stack(stack);
        postfix[i++] = *data_ptr;
        free(data_ptr);
    }

    printf("Postfix formula: %s\n", postfix);
    destory_stack(stack);


    /// evaluate
    
}

#endif // __STACK_OPERATION_H__