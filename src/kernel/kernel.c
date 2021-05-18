#include <stdbool.h>

#include "devices/fb.h"
#include "devices/serial.h"

void kmain
(
     void
)
{
    puts
    (
         "Hello World"
    );
    serial_puts
    (
         COM1,
	 "Blumen succesfully booted \n"
    );
    while
    (
         true
    );
}
