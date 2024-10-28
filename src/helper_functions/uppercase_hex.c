/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uppercase_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbartusc <gbartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:34:01 by gbartusc          #+#    #+#             */
/*   Updated: 2024/10/28 10:42:49 by gbartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	uppercase_hex(size_t num)
{
	int	count;

	count = 0;
	if (num >= 16)
	{
		count += uppercase_hex(num / 16);
		num %= 16;
	}
	if (num <= 9)
		count += ft_putchar(num + '0');
	else
		count += ft_putchar(num - 10 + 'A');
	return (count);
}
