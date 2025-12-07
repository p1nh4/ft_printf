/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_specifier_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:28:30 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/07 21:48:11 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_process_specifier_bonus(char format, va_list args, t_flags *flags)
{
	int		lower_case;
	int		upper_case;
	size_t	t_len;

	t_len = 0;
	lower_case = 1;
	upper_case = 0;
	if (format == 'c')
		t_len += ft_print_char_bonus(va_arg(args, int), flags);
	else if (format == 's')
		t_len += ft_print_str_bonus(va_arg(args, char *), flags);
	else if (format == 'p')
		t_len += ft_print_ptr_bonus(va_arg(args, void *), flags);
	else if (format == 'd')
		t_len += ft_print_int_bonus(va_arg(args, int), flags);
	else if (format == 'i')
		t_len  += ft_print_int_bonus(va_arg(args, int), flags);
	else if (format == 'u')
		t_len += ft_print_uint_bonus(va_arg(args, unsigned int), flags);
	else if (format == 'x')
		t_len += ft_print_hex_bonus(va_arg(args, unsigned int), lower_case, flags);
	else if (format == 'X')
		t_len += ft_print_hex_bonus(va_arg(args, unsigned int), upper_case, flags);
	else if (format == '%')
		t_len += ft_print_percent_bonus('%', flags);
	return (t_len);
}
