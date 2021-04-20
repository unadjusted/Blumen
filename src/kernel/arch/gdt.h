#ifndef GDT_H
#define GDT_H

#include <stdint.h>

#define KERNEL 0b00000000
#define USER 0b01100000
#define CODE 0b00011000
#define DATA 0b00010000
#define GRANULARITY 0b00100000

void init_gdt (void);

typedef struct __attribute__((packed))
{
  uint16_t base;
  uint64_t limit;
}gdt_pointer;

typedef struct __attribute__((packed))
{
  uint16_t low_limit;
  uint16_t low_base;
  uint8_t base;
  uint8_t flag;
  uint8_t high_limit;
  uint8_t granularity;
  uint8_t high_base;
}segment;
#endif
