#include "stdout.h"
#include <stddef.h>
#include "../../headers/functions/stdfunc.h"
#include "vga.h"

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) 
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}
 
void terminal_putchar(char c)
{
    if(terminal_column == VGA_WIDTH || c == '\n'){
        terminal_column = 0;
        if(terminal_row == VGA_HEIGHT-1){
            terminal_row = 0;
        } else {
            terminal_row++;
        }
    }
    if(c == '\n') return;
    terminal_putentryat(c, terminal_color, terminal_column++, terminal_row);
}
void terminal_write(const char* data, size_t size) 
{
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}
 
void terminal_puts(const char* data) 
{
	terminal_write(data, strlen(data));
}
void terminal_endl (void)
{
terminal_putchar('\n');
}
void terminal_putsline(const char* data)
{
terminal_puts(data);
terminal_endl();
}