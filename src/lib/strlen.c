#include "string.h"

/* I make it now because strlen() is useful */
int strlen(char *str)
{
    int lenght=0;
    	while (str[lenght])
        {
		lenght++;
        }
	return lenght;
}