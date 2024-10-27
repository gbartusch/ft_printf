/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbartusc <gbartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:32:40 by gbartusc          #+#    #+#             */
/*   Updated: 2024/10/27 19:02:24 by gbartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_letter(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 's' || c == 'p')
		count += convert_case2(c, args);
	else if (c == 'x' || c == 'X')
		count += convert_case3(c, args);
	else if (c == 'c' || c == 'd' || c == 'i' || c == 'u')
		count += convert_case1(c, args);
	return (count);
}

int	conversions(char conversion)
{
	return (conversion == 'c' || conversion == 's' || conversion == 'd'
		|| conversion == 'i' || conversion == 'u' || conversion == 'x'
		|| conversion == 'X' || conversion == 'p');
}

int	handle_format(const char *format, va_list args)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				count += ft_putchar(format[i]);
			}
			else if (!conversions(format[i]))
				return (invalid_conversion(format[i]));
			else
				count += check_letter(format[i], args);
		}
		else
			count += ft_putchar(format[i]);
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

// #include <stdio.h>
// int	main(void)
// {
// 	int		len;
// 	int		len1;
// 	char	*ptr = 0;
// 	len = 0;
// 	len1 = 0;
// 	ft_printf("Testing single integer: %d\n", 5);
// 	// ft_printf("Testing single string: %s\n", (char *)0);
// 	len = printf("or:  NULL %s NULL \n", NULL);
// 	len1 = ft_printf("ft:  NULL %s NULL \n", NULL);
// 	printf("%d - %d\n", len, len1);
// 	ft_printf("Testing single pointer: %p\n", ptr);
// 	printf("Testing single pointer: %p\n", ptr);
// 	ft_printf("Testing unsigned decimal: %u\n", 3000000000);
// 	ft_printf("Testing single integer : %i\n", 101);
// 	ft_printf("Testing lowercase hexadecimal number : %x\n", 0xde5);
// 	ft_printf("Testing uppercase hexadecimal number : %X\n", 0xDE5);
// 	len = ft_printf("Hello %d world! %c Life %s\n", 42, 'x', "Codam");
// 	len1 = printf("Hello %d world! %c Life %s\n", 42, 'x', "Codam");
// 	ft_printf("Characters in total: %d\n", len);
// 	printf("Characters in total: %d\n", len1);
// 	return 0;
// }
