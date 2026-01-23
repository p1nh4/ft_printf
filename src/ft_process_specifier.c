/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_specifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:28:30 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/23 20:43:14 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_process_specifier(char format, va_list args)
{
	size_t	t_len;

	t_len = 0;
	if (format == 'c')
		t_len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		t_len += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		t_len += ft_print_ptr(va_arg(args, void *));
	else if (format == 'd')
		t_len += ft_print_int(va_arg(args, int));
	else if (format == 'i')
		t_len += ft_print_int(va_arg(args, int));
	else if (format == 'u')
		t_len += ft_print_uint(va_arg(args, unsigned int));
	else if (format == 'x')
		t_len += ft_print_hex(va_arg(args, unsigned int), LOWER_CASE);
	else if (format == 'X')
		t_len += ft_print_hex(va_arg(args, unsigned int), UPPER_CASE);
	else if (format == '%')
		t_len += ft_print_percent('%');
	return (t_len);
}
