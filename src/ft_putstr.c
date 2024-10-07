#include "ft_printf.h"

int ft_putstr(char *str) 
{
	int	count;

	count = 0;
	if (!str) 
	{
		char *null_str = "(null)";
		while (*null_str)
		{
    		ft_putchar(*null_str);
			null_str++;
			count++;
		}
		return (count);
	}
    while (*str != '\0') 
	{
        ft_putchar(*str);
        str++;
		count++;
    }
	return (count);
}