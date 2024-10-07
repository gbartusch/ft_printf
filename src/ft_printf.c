#include "ft_printf.h"

int convert_case(char c, va_list *args)
{
	int	count;

	count = 0;
	if (c == 'd')
	{
		int val = va_arg(*args, int);
		count = ft_putnbr(val);
	}
	else if (c == 'c')
	{
        int z = va_arg(*args, int);
		ft_putchar((char)z);
		count = 1;
	}
	else if (c == 's')
	{
		char* string = va_arg(*args, char*);
		count = ft_putstr(string);
	}
	return (count);
}

int	handle_format(const char *format, va_list args)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (*format == '%')
			{
				write(1, &format[i], 1);
			}
			count += convert_case(format[i], &args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = handle_format(format, args);
	va_end(args);
	return (count);
}

int	main()
{
	int len;
	len = ft_printf("Testing single char: %s and then integer: %d and then string: %c\n", "Hello", 22, 'a');
	ft_printf("The length of the entire string above is: %d", len);
	ft_printf("Testing single integer: %d\n", 5);
	ft_printf("Testing single string: %s\n", "Hello");
	ft_printf("Hello %d world! %c Life %s\n", 42, 'x', "Tree");
	
	return 0;
}