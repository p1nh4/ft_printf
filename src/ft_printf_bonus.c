/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:13:19 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/23 23:21:44 by davidos-         ###   ########.fr       */
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

static int	ft_process_format_str(const char **format, va_list args)
{
	int		t_len;
	t_flags	flags;

	t_len = 0;
	while (**format)
	{
		if (**format == '%')
		{
			(*format)++;
			if (!*format)
				break ;
			ft_init_flags(&flags);
			ft_parse_flags_bonus(format, &flags);
			if (*format && ft_strchr("cspdiuxX%", **format))
				t_len += ft_process_specifier_bonus(**format++, args, &flags);
		}
		else
		{
			ft_putchar_fd(**format++, 1);
			t_len++;
		}
	}
	return (t_len);
}

int	ft_printf(const char *format, ...)
{
	int		t_len;
	va_list	args;

	t_len = 0;
	if (!format || (*format == '%' && *(format + 1) == '\0'))
		return (-1);
	va_start(args, format);
	t_len += ft_process_format_str(&format, args);
	va_end(args);
	return (t_len);
}
