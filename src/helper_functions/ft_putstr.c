/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbartusc <gbartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:33:50 by gbartusc          #+#    #+#             */
/*   Updated: 2024/10/25 16:01:36 by gbartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int		count;
	char	*null_str;

	count = 0;
	if (!str)
	{
		null_str = "(null)";
		while (*null_str)
		{
			ft_putchar(*null_str);
			null_str++;
			count++;
		}
		return (count);
	}
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
		count++;
	}
	return (count);
}
