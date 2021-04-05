#include <stdint.h>
#include <stddef.h>

void outb(uint16_t dest, uint8_t source)
{
    __asm__ __volatile__ ( "outb %0, %1" : : "a"(source), "Nd"(dest) );
}

uint8_t inb(uint16_t source)
{
    uint8_t ret;
   __asm__ __volatile__ ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(source) );
    return ret;
}
