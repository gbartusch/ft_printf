/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_case3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbartusc <gbartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:52:41 by gbartusc          #+#    #+#             */
/*   Updated: 2024/10/25 17:21:18 by gbartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_case3(char c, va_list args)
{
	unsigned int	hex;
	unsigned int	hexi;
	int				count;

	count = 0;
	if (c == 'x')
	{
		hex = va_arg(args, unsigned int);
		write(1, "0x", 2);
		count += 2;
		count += convert_to_hex(hex);
	}
	else if (c == 'X')
	{
		hexi = va_arg(args, unsigned int);
		write(1, "0x", 2);
		count += 2;
		count += uppercase_hex(hexi);
	}
	return (count);
}
