#ifndef GDT_H
#define GDT_H

#include <stdint.h>

#define KERNEL 0b10000010
#define USER 0b11100010
#define CODE 0b00011000
#define DATA 0b00010000

void init_gdt
(
    void
);
void gdtr_install
(
    void
);

typedef struct __attribute__((packed))
{
  uint16_t size;
  uint64_t adress;
}gdt_pointer;

typedef struct __attribute__((packed))
{
  uint16_t low_limit;
  uint16_t low_base;
  uint8_t base;
  uint8_t flag;
  uint8_t high_limit : 4;
  uint8_t granularity : 4;
  uint8_t high_base;
}segment;
#endif
