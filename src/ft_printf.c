/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbartusc <gbartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:32:40 by gbartusc          #+#    #+#             */
/*   Updated: 2024/10/25 17:24:25 by gbartusc         ###   ########.fr       */
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
	else
		count += convert_case1(c, args);
	return (count);
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
				write(1, &format[i], 1);
			}
			check_letter(format[i], args);
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

// int	main(void)
// {
// 	int		len;
// 	char	*ptr = "He78";
// 	char	*ptr1 = malloc(sizeof(int));

// 	len = ft_printf("Testing single char: %s and then integer: %d and \
//  then character: %c and then pointer %p\n", "Hello", 22, 'a', ptr);
// 	ft_printf("The length of the entire string above is: %d", len);
// 	ft_printf("Testing single integer: %d\n", 5);
// 	ft_printf("Testing single string: %s\n", "Hello");
// 	ft_printf("Hello %d world! %c Life %s\n", 42, 'x', "Tree");
// 	ft_printf("Testing single pointer: %p\n", ptr);
// 	ft_printf("Testing single pointer: %p\n", ptr1);
// 	ft_printf("Testing unsigned decimal: %u\n", 3000000000);
// 	ft_printf("Testing single integer : %i\n", 101);
// 	ft_printf("Testing lowercase hexadecimal number : %x\n", 0xde5);
// 	ft_printf("Testing uppercase hexadecimal number : %X\n", 0xDE5);

// 	return 0;
// }