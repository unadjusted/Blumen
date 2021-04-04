#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include "serial.h"
#include "fb.h"
#include "io.h"

int *ports={0,0x3F8,0x2F8, 0x3E8, 0x2E8};
void init_serial(int port_number)
{
    int port=ports[port_number];
    outb(port + 1, 0x00); 
    outb(port + 3, 0x80);
    outb(port + 0, 0x03);   
    outb(port + 1, 0x00); 
    outb(port + 3, 0x03);   
    outb(port + 2, 0xC7);   
    outb(port + 4, 0x0B);    
    outb(port + 4, 0x1E);    
    outb(port + 0, 0xAE);
    outb(port + 4, 0x0F);
    /*serial_putchar("Serial init sucessfully \n", 1);*/
}
 
void serial_putchar(char a, int port_number) 
{
    int port=ports[port_number];
    outb(port,a);
}

void serial_puts(char *str, int port_number)
{
    int i;
    for(i=0; i==strlen(str); i++)
    {
        serial_putchar(str[1], port_number);
    }
}