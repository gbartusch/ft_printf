/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbartusc <gbartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:33:55 by gbartusc          #+#    #+#             */
/*   Updated: 2024/10/27 10:14:34 by gbartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_printf.h"

int	print_address(void *ptr)
{
	int			count;
	uintptr_t	int_ptr;

	int_ptr = (uintptr_t)ptr;
	write(1, "0x", 2);
	count = 2;
	count += convert_to_hex(int_ptr);
	return (count);
}
