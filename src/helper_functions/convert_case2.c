/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_case2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbartusc <gbartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:52:18 by gbartusc          #+#    #+#             */
/*   Updated: 2024/10/25 17:20:52 by gbartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
