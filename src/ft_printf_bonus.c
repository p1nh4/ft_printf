/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:13:19 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/23 21:22:19 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_init_flags(t_flags *flags)
{
	flags->width = 0;
	flags->precision = -1;
	flags->plus = 0;
	flags->minus = 0;
	flags->zeros = 0;
	flags->space = 0;
	flags->hashtag = 0;
}

int	ft_printf(const char *format, ...)
{
	int		t_len = 0;
	va_list	args;
	t_flags	flags;

	if (!format) return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				break ;
			ft_init_flags(&flags);
			ft_parse_flags_bonus(&format, &flags);
			if (*format && ft_strchr("cspdiuxX%", *format))
				t_len += ft_process_specifier_bonus(*format++, args, &flags);
		}
		else
		{
			ft_putchar_fd(*format++, 1);
			t_len++;
		}
	}
	va_end(args);
	return (t_len);
}
