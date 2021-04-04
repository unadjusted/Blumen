#ifndef SERIAL_H
#define SERIAL_H
void init_serial(int port_number);
void serial_putchar(char a, int port_number);
void serial_puts(char *str, int port_number);
#endif