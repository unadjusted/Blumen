/*
Copyright (C) 2020  Freeloo

    This file is a part of duckOS : you can redistribute it and/or modify
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
#include "./headers/basic_output_functions.h"
 
/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You must using a cross compiler !"
#endif
 
/* This tutorial will only work for the 32-bit ix86 targets ! */
#if !defined(__i386__)
#error "You must use an i386 compiler"
#endif
 
/* Hardware text mode color constants. */

 void kernel_boot(void) 
{
	terminal_initialize();
	terminal_puts("Welcome to duck OS, an kernel that i write for fun and learn about OS dev");
	
}