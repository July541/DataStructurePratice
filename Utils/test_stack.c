#include <stdio.h>

#include "../Stack/stack_operation.h"
#include "menu.h"

#define TITLE "Stack operation test"

static const Command commands[] = {
    { "十进制转二进制", "convert_decimal_to_binary", convert_decimal_to_binary },
    { "中缀转后缀并求值", "convert_infix_to_postfix_and_evaluation", convert_infix_to_postfix_and_evaluation }
};

int main(void) {
    printf("sizeof(commands): %d\n", sizeof(commands));
    print_menu(TITLE, commands);
    //convert_infix_to_postfix_and_evaluation();
    return 0;
}