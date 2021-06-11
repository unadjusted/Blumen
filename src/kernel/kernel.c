#include <stdbool.h>

#include "src/includes/fb.h"
#include "src/includes/serial.h"

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
