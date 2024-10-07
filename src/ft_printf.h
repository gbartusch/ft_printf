#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	handle_format(const char *format, va_list args);
int convert_case(char c, va_list *args);
void ft_putchar(char c);
int ft_putnbr(int n);
int ft_putstr(char *str);













#endif