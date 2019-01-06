#ifndef __COMMAND_H__
#define __COMMAND_H__

typedef struct {
    const char* key;
    const char* value;
    void (*func)();
} Command;

#endif // __COMMAND_H_