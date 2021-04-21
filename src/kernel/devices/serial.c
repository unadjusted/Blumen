/**
 * Copyright (C) 2020-2021 KeyboardSlayer (Jordan Dalcq)
 * 
 * This file is part of Navy.
 * 
 * Navy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Navy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Navy.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stddef.h>
#include <stdint.h>

#include "serial.h"
#include "io.h"

void 
init_serial(enum PORT port)
{
    outb(port + 1, 0x00);   
    outb(port + 3, 0x80);    
    outb(port + 0, 0x03);    
    outb(port + 1, 0x00);    
    outb(port + 3, 0x03);    
    outb(port + 2, 0xC7);    
    outb(port + 4, 0x0B);
    serial_puts(COM1, "-->Serial succesfully initialized \n");
}

static int 
is_transmit_empty(enum PORT port)
{
    return inb(port + 5) & 0x20;
}

void
putc_serial(enum PORT port, char c)
{
    while (is_transmit_empty(port) == 0);

    outb(port, c);
}

void 
serial_puts(enum PORT port, const char *s)
{
    size_t i;

    for (i = 0; s[i] != '\0'; i++)
    {
        putc_serial(port, s[i]);
    }
}