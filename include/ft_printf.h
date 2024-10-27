/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbartusc <gbartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:53:41 by gbartusc          #+#    #+#             */
/*   Updated: 2024/10/27 17:54:52 by gbartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define _RED		"\e[1;31m"
# define _WHITE		"\e[1;37m"
# define _RESET		"\e[0m"

int		ft_printf(const char *format, ...);
int		handle_format(const char *format, va_list args);
int		convert_case1(char c, va_list args);
int		convert_case2(char c, va_list args);
int		convert_case3(char c, va_list args);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		print_address(void *ptr);
int		convert_to_hex(size_t	num);
int		ft_putnbr_unsigned(unsigned int n);
int		uppercase_hex(size_t	num);
void	print_error(void);
int		invalid_conversion(char conversion);
int		ft_strlen(char *str);
int		invalid_format(void);

#endif