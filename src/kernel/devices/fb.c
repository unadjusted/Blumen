#include <stddef.h>

#include "src/includes/string.h"
#include "src/includes/fb.h"

#define FRAME_BUFFER 0x000B8000

int i;
int place=0;
char *frame_buffer = (char *) FRAME_BUFFER;

void putchar
(
    char str
)
{
    frame_buffer[place]=str;
    place+=2;
}

void puts
(
    char *str
)
{
    for
    (
        i=0;
	i<strlen(str);
	i++
    )
    {
        putchar
        (
	    str[i]
	);
    }
}
