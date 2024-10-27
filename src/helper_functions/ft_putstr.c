/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbartusc <gbartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:33:50 by gbartusc          #+#    #+#             */
/*   Updated: 2024/10/27 10:16:08 by gbartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

int	ft_putstr(char *str)
{
	int		count;

	count = 0;
	if (!str)
	{
		write (1, "(null)", 7);
		count += 6;
		return (count);
	}
	write (1, str, ft_strlen(str));
	return (ft_strlen(str));
}
