#ifndef GDT_H
#define GDT_H

#include <stdint.h>

void init_gdt (void);

typedef struct __attribute__((packed))
{
  uint16_t base;
  uint64_t limit;
}segment_pointer;

typedef struct __attribute__((packed))
{
  uint16_t low_limit;
  uint16_t low_base;
  uint8_t base;
  uint8_t flag;
  uint8_t high_limit; /* this include the high limit and the granularity */
  uint8_t high_base;
}segment;
#endif
