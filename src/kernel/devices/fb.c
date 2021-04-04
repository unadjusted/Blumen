#include <stddef.h>

#include "../../lib/string.h"
#include "fb.h"

int i;
int place=0;
char *frame_buffer = (char *) 0x000B8000;

void putchar(char str)
{
    frame_buffer[place]=str;
    place+=2;
}

void puts(char *str)
{
    for( i=0;i<strlen(str); i++)
    {
        putchar(str[i]);
    }
}