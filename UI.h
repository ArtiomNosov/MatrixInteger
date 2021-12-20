#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef UI
#define UI

enum Menu
{
    EXIT,
    SHOW
};

enum ErrorCodesUI {
    OK = 0,
    NoMemory = -1
};

char *get_str();
int errorNoMemory(void* ptr);

#endif
