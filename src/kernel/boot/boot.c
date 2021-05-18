#include <stdint.h>
#include <stddef.h>

#include "stivale2.h"
#include "../kernel.h"
#include "../devices/serial.h"
#include "../arch/gdt.h"

int boot
(
    struct stivale2_struct stivale2_struct
);
uint8_t stack[4096];

__attribute__((section(".stivale2hdr"), used))
struct stivale2_header header = 
{
    .entry_point = (uint64_t) boot, 
    .stack = (uintptr_t)stack, 
    .flags = 0, 
    .tags = NULL 
    };

int boot
(
    struct stivale2_struct stivale2_struct
)
{
  
    init_serial
    (
        COM1
    );
    init_gdt
    (
        void
    );
    kmain
    (
        void
    );
    return 0;
}
