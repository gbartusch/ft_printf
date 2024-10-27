/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbartusc <gbartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:14:25 by gbartusc          #+#    #+#             */
/*   Updated: 2024/10/27 18:05:31 by gbartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	print_error(void)
{
	write(2, _RED "ft_printf error: ", 24);
}

int	invalid_conversion(char conversion)
{
	print_error();
	write(2, _WHITE "invalid conversion specifier '", 37);
	write(2, &conversion, 1);
	write(2, "'\n" _RESET, 2);
	return (-1);
}
