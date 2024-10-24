#include "ft_printf.h"

int ft_putnbr_unsigned(unsigned int n) 
{
    int	count;

	count = 0;
	if (n > 9) 
	{
        ft_putnbr(n / 10);
        count++;
    }
    ft_putchar((n % 10) + '0');
	count++;

	return (count);
}
