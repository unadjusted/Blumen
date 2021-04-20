#include <stdint.h>

#include "gdt.h"

segment gdt[5];
segment_pointer ptr;

segment null_segment =
{
 .low_limit = 0,
 .low_base = 0,
 .base = 0,
 .flag = 0,
 .high_limit = 0,
 .high_base = 0
};

segment kernel_code =
{
  .low_limit = 0xFFFF,
  .low_base= 0x0000,
  .base = 0b00,
  .flag = 0b01011001,
  .high_limit = 0xF4,
  .high_base = 0x00
};

segment kernel_data = 
{
  .low_limit = 0xFFFF,
  .low_base = 0x0000,
  .base = 0b00,
  .flag = 0b10010010,
  .high_limit = 0xF4,
  .high_base = 0x00
};

segment user_code =
{
  .low_limit = 0xFFFF,
  .low_base = 0x0000,
  .base = 0b00,
  .flag = 0b11110010,
  .high_limit = 0xF4,
  .high_base = 0x00
};

segment user_data =
{
  .low_limit=0xFFFF,
  .low_base = 0x0000,
  .base = 0b00,
  .flag = 0b11110010,
  .high_limit = 0xF0,
  .high_base = 0x00
};

  void init_gdt(void)
{
  gdt[0] = null_segment;
  gdt[1] = kernel_code;
  gdt[2] = kernel_data;
  gdt[3] = user_code;
  gdt[4] = user_data;
  ptr.base = (uintptr_t)&gdt[0];
  ptr.limit = sizeof(gdt)- 1;
  gdt_flush((uintptr_t)&ptr);
  serial_puts(0x3F8, "-->GDT successfully initialized \n");
};
