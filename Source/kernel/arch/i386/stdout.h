#ifndef TERMINAl_OUTPUT_H
#define TERMINAl_OUTPUT_H
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "../../headers/functions/stdfunc.h"

void putchar(char data, int place);


void putchar(char data, int place)
{
char *out = (char *) 0x000B8000;
out[place] = data;
out[++place] = 0x17;
}
#endif