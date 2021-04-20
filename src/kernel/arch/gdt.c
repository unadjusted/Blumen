#include <stdint.h>

#include "gdt.h"
#include "../devices/serial.h"

segment gdt[5];
gdt_pointer gdtr;

segment null_segment =
{
 .low_limit = 0,
 .low_base = 0,
 .base = 0,
 .flag = 0,
 .high_limit = 0,
 .granularity = 0,
 .high_base = 0
};

segment kernel_code =
{
  .low_limit = 0xFFFF,
  .low_base= 0,
  .base = 0,
  .flag = KERNEL | CODE,
  .high_limit = 0xF,
  .granularity = GRANULARITY,
  .high_base = 0
};

segment kernel_data = 
{
  .low_limit = 0xFFFF,
  .low_base = 0,
  .base = 0,
  .flag = KERNEL | DATA,
  .high_limit = 0xF,
  .granularity = GRANULARITY ,
  .high_base = 0
};

segment user_code =
{
  .low_limit = 0xFFFF,
  .low_base = 0,
  .base = 0,
  .flag = USER | CODE,
  .high_limit = 0xF,
  .granularity = GRANULARITY,
  .high_base = 0
};

segment user_data =
{
  .low_limit=0xFFFF,
  .low_base = 0,
  .base = 0,
  .flag = USER | DATA,
  .high_limit = 0xF,
  .granularity = GRANULARITY,
  .high_base = 0
};

  void init_gdt(void)
{
  gdt[0] = null_segment;
  gdt[1] = kernel_code;
  gdt[2] = kernel_data;
  gdt[3] = user_code;
  gdt[4] = user_data;
  gdtr.base = (uintptr_t)&gdt[0];
  gdtr.limit = sizeof(gdt)- 1;
  serial_puts(COM1, "Loading GDT... \n");
  gdtr_init((uintptr_t)&gdtr);
  serial_puts(COM1, "-->GDT successfully initialized \n");
};
