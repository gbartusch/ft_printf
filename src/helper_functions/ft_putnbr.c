#include "ft_printf.h"

int ft_putnbr(int n) 
{
	int	count;

	count = 0;
    if (n == -2147483648)
    {
        ft_putstr("-2147483648");
		return 11;
    }
	if (n < 0) 
	{
        ft_putchar('-');
        n = -n;
		count++;
    }
	if (n > 9) 
	{
        ft_putnbr(n / 10);
        count++;
    }
    ft_putchar((n % 10) + '0');
	count++;

	return (count);
}