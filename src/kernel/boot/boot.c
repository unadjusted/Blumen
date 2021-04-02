#include <stdint.h>
#include <stddef.h>

#include "stivale2.h"
#include "../devices/fb.h"
#include "../kernel.h"

int boot(struct stivale2_struct stivale2_struct);
uint8_t stack[4096];
struct stivale2_header header = 
{
    .entry_point = &boot, 
    .stack = &stack, 
    .flags = 0, 
    .tags = NULL 
    };

int boot(struct stivale2_struct stivale2_struct)
{
    puts("hello world");  
    kmain();
    return(0);
}