#ifndef __MENU_H__
#define __MENU_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "command.h"

void print_header(const char* head_name) {
    puts(head_name);
}

void print_menu(const char* title, const Command* commands) {
    int i, command_len, choice;

    print_header(title);

    command_len = sizeof(commands) / sizeof(Command);
    printf("sizeof(commands): %d\n", sizeof(*commands));

    while (1) {
        for (i = 0; i < command_len; i++) {
            printf("%d. %s\n", i + 1, commands[i].key);
        }

        printf("\nType a number(0 quit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            return;
        }
        else if (choice >= 1 && choice <= command_len) {
            commands[choice - 1].func();
        }

    }
}

// Load function name from corresponding config files.
// More detail can be seen in config files.
char* load_config(const char* cfg_name, const char* key_name) {
    FILE *fp;
    char* value_name;

    fp = fopen(cfg_name, "r");
    if (fp == NULL) {
        printf("Can not open %s.\n", cfg_name);
    }

    while (fscanf(fp, " %m[^ ] ", &value_name)) {
        if (strcmp(key_name, value_name) == 0) {
            free(value_name);

            fscanf(fp, " %m[^\n]\n", &value_name);
            return value_name;
        }
        else {
            free(value_name);
            fscanf(fp, " %m[^\n]\n", &value_name);
        }
    }
    return NULL;
}

#endif // __MENU_H__