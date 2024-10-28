/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbartusc <gbartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:33:55 by gbartusc          #+#    #+#             */
/*   Updated: 2024/10/28 10:51:19 by gbartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_printf.h"

int	print_address(void *ptr)
{
	uintptr_t	int_ptr;

	if (ptr == 0)
		return (write(1, "(nil)", 5));
	else
	{
		int_ptr = (uintptr_t)ptr;
		return ((write(1, "0x", 2)) + convert_to_hex(int_ptr));
	}
}
