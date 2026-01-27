/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:52:28 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/27 21:45:34 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//(format + 1) nao move o ptr, format++ sim

static int	ft_process_format(const char **format, va_list args)
{
	int	t_len;

	t_len = 0;
	while (**format)
	{
		if (**format == '%')
		{
			(*format)++;
			if (!**format || !ft_strchr("cspdiuxX%", **format))
			{
				va_end(args);
				return (-1);
			}
			t_len += ft_process_specifier(**format, args);
		}
		else
		{
			ft_putchar_fd(**format, 1);
			t_len++;
		}
		(*format)++;
	}
	return (t_len);
}

int	ft_printf(const char *format, ...)
{
	int		t_len;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	t_len = ft_process_format(&format, args);
	va_end(args);
	if (t_len == -1)
		return (-1);
	return (t_len);
}
