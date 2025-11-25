/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:28:30 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/25 17:07:13 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_printf_conv(char format, va_list args)
{
	int		lower_case;
	int		upper_case;
	size_t	t_len;

	t_len = 0;
	lower_case = 1;
	upper_case = 0;
	if (format == 'c')
		t_len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		t_len += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		t_len += ft_print_ptr(va_arg(args, void *));
	else if (format == 'd')
		t_len += ft_print_int(va_arg(args, int));
	else if (format == 'i')
		t_len  += ft_print_int(va_arg(args, int));
	else if (format == 'u')
		t_len += ft_print_uint(va_arg(args, unsigned int));
	else if (format == 'x')
		t_len += ft_print_hex(va_arg(args, unsigned int), lower_case);
	else if (format == 'X')
		t_len += ft_print_hex(va_arg(args, unsigned int), upper_case);
	else if (format == '%')
		t_len += ft_print_percent('%');
	return (t_len);
}
