#ifndef IDT_H
#define IDT_H

#include <stdint.h>

#include "io.h"

typedef struct __attribute__((packed))
{
    uint16_t offset_low;
    uint16_t segment_selector;
    uint8_t ist_index;
    uint8_t attr;
    uint16_t offset_middle;
    uint32_t offset_high;
    uint32_t zero;
}idt_entry;

typedef struct __attribute__((packed))
{
    uint16_t size;
    uint64_t addr;
}idt_pointer;

#endif
