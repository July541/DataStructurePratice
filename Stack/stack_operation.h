#ifndef __STACK_OPERATION_H__
#define __STACK_OPERATION_H__

#include <stdio.h>

#include "stack.h"

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

#endif // __STACK_OPERATION_H__