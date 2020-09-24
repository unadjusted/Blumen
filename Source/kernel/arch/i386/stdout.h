#ifndef TERMINAl_OUTPUT_H
#define TERMINAl_OUTPUT_H
#include <stddef.h>
#include "vga.h"

void terminal_puts(const char* data);
void terminal_endl (void);
void terminal_putsline(const char* data);
void terminal_write(const char* data, size_t size);
void terminal_putchar(char c);
#endif