#ifndef GDT_H
#define GDT_H

#include <stdint.h>

struct segment_register
{
  uint16_t size;
  uint64_t adress;
}__attribure_packed ;

struct segment
{
  uint16_t low_limit;
  uint16_t low_base;
  uint8_t base;
  uint8_t flag;
  uint8_t high_limit; /* this include the high limit and the granularity */
  uint8_t high_base;
}__attribute_packed__;


struct segment null_segment =
{
 .low_limit = 0,
 .low_base = 0,
 .base = 0,
 .flag = 0,
 .high_limit = 0,
 .high_base = 0
};

struct segment kernel_code =
{
  .low_limit = 0xFFFF,
  .low_base= 0x0000,
  .base = 0x00,
  .flag = 0x01011001,
  .high_limit = 0xF4,
  .high_base = 0x00
};

struct segment kernel_data = 
{
  .low_limit = 0xFFFF,
  .low_base = 0x0000,
  .base = 0x00,
  .flag = 0x01010001,
  .high_limit = 0xF4,
  .high_base = 0x00
};
#endif
