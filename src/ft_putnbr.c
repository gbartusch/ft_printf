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
        count += ft_putnbr(n / 10);
    }
    ft_putchar('0' + (n % 10));
	count++;

	return (count);
}