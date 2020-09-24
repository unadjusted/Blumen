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
#include "../headers/functions/stdfunc.h"
#include "../arch/i386/.h"
#if defined(__linux__)
#error "You must using a cross compiler !"
#endif
 #if !defined(__i386__)
#error "You must use an i386 compiler"
#endif

 void kernel_boot(void) 
{
	terminal_initialize();
	terminal_putsline("Welcome to duck OS, an kernel that i write for fun and learn about OS dev \n");
	terminal_putsline("      _            _       ____   _____ ");
	terminal_putsline("     | |          | |     / __ \\ / ____|");
	terminal_putsline("   __| |_   _  ___| | __ | |  | | (___  ");
	terminal_putsline("  / _` | | | |/ __| |/ / | |  | |\\___ \\ ");
	terminal_putsline(" | (_| | |_| | (__|   \\  | |__| |____) |");
	terminal_putsline("  \\__,_|\\__,_|\\___|_|\\_\\  \\____/|_____/ ");
};