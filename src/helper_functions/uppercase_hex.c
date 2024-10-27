/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uppercase_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbartusc <gbartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:34:01 by gbartusc          #+#    #+#             */
/*   Updated: 2024/10/27 09:46:06 by gbartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	uppercase_hex_16(size_t num)
{
	int	count;

	count = 0;
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
	return (count);
}

int	uppercase_hex(size_t num)
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
		count += uppercase_hex_16(num);
	return (count);
}
