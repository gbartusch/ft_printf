#include "ft_printf.h"

int	uppercase_hex(size_t	num)
{
	int	count;

	count = 0;
	if (num <= 9)
	{
		ft_putchar(num + '0');
		count++;
	}
	else if (num > 9 && num < 16)
	{
		ft_putchar(num % 10 + 'A');
		count++;
	}
	else if (num >= 16)
	{
		count += uppercase_hex(num / 16);
		if ((num % 16) <= 9)
		{
			ft_putchar(num % 16 + '0');
			count++;
		}
		else
		{
			ft_putchar((num % 16) % 10 + 'A');
			count++;
		}
	}
	return(count);
}