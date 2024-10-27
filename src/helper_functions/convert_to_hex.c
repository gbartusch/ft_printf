/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbartusc <gbartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:32:51 by gbartusc          #+#    #+#             */
/*   Updated: 2024/10/27 11:31:24 by gbartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_to_hex(size_t num)
{
	int	count;

	count = 0;
	if (num <= 9)
		ft_putchar(num + '0');
	else if (num > 9 && num < 16)
		ft_putchar(num % 10 + 'a');
	else if (num >= 16)
	{
		count += convert_to_hex(num / 16);
		if ((num % 16) <= 9)
			ft_putchar(num % 16 + '0');
		else
			ft_putchar((num % 16) % 10 + 'a');
	}
	count++;
	return (count);
}
