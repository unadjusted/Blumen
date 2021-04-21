#include "io.h"

void 
outb(uint16_t port, uint8_t val)
{
    __asm__ volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

uint8_t 
inb(uint16_t port)
{
    uint8_t ret;
    __asm__ volatile ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}

void 
outw(uint16_t port, uint16_t val)
{
    __asm__ volatile ( "outw %0, %1" : : "a"(val), "Nd"(port) );
}

uint16_t 
inw(uint16_t port)
{
    uint16_t ret;
    __asm__ volatile ( "inw %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}

/*
void 
outd(uint16_t port, uint8_t val)
{
    asm volatile ( "outd %0, %1" : : "a"(val), "Nd"(port) );
}
uint32_t 
ind(uint16_t port)
{
    uint32_t ret;
    asm volatile ( "ind %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}*/

void
io_wait(void)
{
    __asm__ volatile ("jmp 1f\n\t" "1:jmp 2f\n\t" "2:");
}