/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbartusc <gbartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:51:50 by gbartusc          #+#    #+#             */
/*   Updated: 2024/10/27 11:18:03 by gbartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_case1(char c, va_list args)
{
	int				count;
	int				val;
	unsigned int	dec;
	int				z;

	count = 0;
	if (c == 'd' || c == 'i')
	{
		val = va_arg(args, int);
		count += ft_putnbr(val);
	}
	else if (c == 'u')
	{
		dec = va_arg(args, unsigned int);
		count += ft_putnbr_unsigned(dec);
	}
	else if (c == 'c')
	{
		z = va_arg(args, int);
		count += ft_putchar((char)z);
	}
	return (count);
}

int	convert_case2(char c, va_list args)
{
	char			*string;
	void			*pointer;
	int				count;

	count = 0;
	if (c == 's')
	{
		string = va_arg(args, char *);
		count += ft_putstr(string);
	}
	else if (c == 'p')
	{
		pointer = va_arg(args, void *);
		count += print_address(pointer);
	}
	return (count);
}

int	convert_case3(char c, va_list args)
{
	unsigned int	hex;
	int				count;

	count = 0;
	hex = va_arg(args, unsigned int);
	if (c == 'x')
		count += convert_to_hex(hex);
	else if (c == 'X')
		count += uppercase_hex(hex);
	return (count);
}
