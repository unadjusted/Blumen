/*
Copyright (C) 2020  Paul Freland

    This file is a part of Blumen OS : you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "io.h"

#define com1   0x3F8

void init_serial() {
   outb(com1 + 1, 0x00);    // Disable all interrupts
   outb(com1 + 3, 0x80);    // Enable DLAB (set baud rate divisor)
   outb(com1 + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
   outb(com1 + 1, 0x00);    //                  (hi byte)
   outb(com1 + 3, 0x03);    // 8 bits, no parity, one stop bit
   outb(com1 + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
   outb(com1 + 4, 0x0B);    // IRQs enabled, RTS/DSR set
}

int serial_read() {
   return inb(com1 + 5) & 1;
}
 
char serial_readchar() 
{
   while (serial_read() == 0);
 
   return inb(com1);
}

int serial_empty() {
   return inb(com1 + 5) & 0x20;
}
 
void serial_putchar(char data) 
{
   while (serial_empty() == 0);
    outb(com1,data);
}
void serial_puts(char *data)
{
    for (int i=0;i<strlen(data);i++)
    {
        serial_putchar(data[i]);
    }
}
