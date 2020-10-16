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
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "../headers/functions/stdfunc.h"
#include "../arch/i386/stdout.h"
#include "../arch/i386/serial.h"
#include "../arch/i386/gdt.h"
#if defined(__linux__)
#error "You must using a cross compiler !"
#endif
 #if !defined(__i386__)
#error "You must use an i386 compiler"
#endif

 void kernel_boot(void) 
{
    init_gdt();
    serial_puts("Gdt is OK \n");
    serial_puts("You can write text to print him on the screen \n");
    puts("Here is BlumenOS, a little kernel write in C !");
     serial_putchar('\n');
    for(;;)
    {
    char data = serial_readchar();
    serial_putchar(data);
    putchar(data);
    }
};