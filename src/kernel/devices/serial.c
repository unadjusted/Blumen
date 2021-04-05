#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include "serial.h"
#include "fb.h"
#include "io.h"
#include "../../lib/string.h"

uint16_t *ports={0,0x3F8,0x2F8, 0x3E8, 0x2E8};
int init_serial(int port_number)
{
    uint16_t port=ports[port_number];
    outb(port + 1, 0x00); 
    outb(port + 3, 0x80);
    outb(port + 0, 0x03);   
    outb(port + 1, 0x00); 
    outb(port + 3, 0x03);   
    outb(port + 2, 0xC7);   
    outb(port + 4, 0x0B);    
    outb(port + 4, 0x1E);
    
    outb(port, 0xAE);
    if(inb(port) != 0xAE) 
    {
        puts("serial initialization failed");
        return 1;
    }
    else
    {
        outb(port + 4, 0x0F);
        puts("Serial successfully initialized");
        return 0;
    }
}
 
void serial_putchar(char str, int port_number) 
{
    uint16_t port=ports[port_number];
    while (is_transmit_empty() == 0);
    outb(port,str);
}

int is_transmit_empty(int port_number) 
{
    uint16_t port=ports[port_number];

    return inb(port+5) & 0x20;
}

void serial_puts(char *str, int port_number)
{
    int i;
    for(i=0; i==strlen(str); i++)
    {
        serial_putchar(str[1], port_number);
    }
}