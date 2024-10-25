/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_case1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbartusc <gbartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:51:50 by gbartusc          #+#    #+#             */
/*   Updated: 2024/10/25 16:52:57 by gbartusc         ###   ########.fr       */
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
		ft_putchar((char)z);
		count += 1;
	}
	return (count);
}
