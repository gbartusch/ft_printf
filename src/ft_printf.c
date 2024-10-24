#include "ft_printf.h"

int convert_case(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
	{
		int val = va_arg(args, int);
		count += ft_putnbr(val);
	}
	else if (c == 'u')
	{
		unsigned int dec = va_arg(args, unsigned int);
		count += ft_putnbr_unsigned(dec);
	}
	else if (c == 'c')
	{
        int z = va_arg(args, int);
		ft_putchar((char)z);
		count += 1;
	}
	else if (c == 's')
	{
		char* string = va_arg(args, char*);
		count += ft_putstr(string);
	}
	else if (c == 'p')
	{
		void* pointer = va_arg(args, void*);
		count += print_address(pointer);
	}
	else if (c == 'x')
	{
		unsigned int hex = va_arg(args, unsigned int);
		write(1, "0x", 2);
		count += 2;
		count += convert_to_hex(hex);
	}
	else if (c == 'X')
	{
		unsigned int hexi = va_arg(args, unsigned int);
		write(1, "0x", 2);
		count += 2;
		count += uppercase_hex(hexi);
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
			if (format[i] == '%')
			{
				write(1, &format[i], 1);
			}
			count += convert_case(format[i], args);
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
	char *ptr = "He78";
	char *ptr1 = malloc(sizeof(int));

	len = ft_printf("Testing single char: %s and then integer: %d and then string: %c and then pointer %p\n", "Hello", 22, 'a', ptr);
	ft_printf("The length of the entire string above is: %d", len);
	ft_printf("Testing single integer: %d\n", 5);
	ft_printf("Testing single string: %s\n", "Hello");
	ft_printf("Hello %d world! %c Life %s\n", 42, 'x', "Tree");
	ft_printf("Testing single pointer: %p\n", ptr);
	ft_printf("Testing single pointer: %p\n", ptr1);
	ft_printf("Testing unsigned decimal: %u\n", 3000000000);
	ft_printf("Testing single integer : %i\n", 101);
	ft_printf("Testing lowercase hexadecimal number : %x\n", 0xde5);
	ft_printf("Testing uppercase hexadecimal number : %X\n", 0xDE5);

	return 0;
}