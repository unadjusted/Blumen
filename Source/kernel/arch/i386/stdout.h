/*
Copyright (C) 2020  Freeloo

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

#ifndef TERMINAl_OUTPUT_H
#define TERMINAl_OUTPUT_H
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "../../headers/functions/stdfunc.h"

int collumn = 0;
int line = 0;
void putchar(char data)
{
int place = collumn*line;
char *out = (char *) 0x000B8000;
if(data!='\n')
{
out[place] = data;
out[++place] = 0x0A;
collumn++;
}
else
{
    line++;
}
}
void puts(char *data)
{
    for (int i=0;i<strlen(data);i++)
    {
        putchar(data[i]);
    }
}

#endif