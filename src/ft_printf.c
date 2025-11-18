/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:52:28 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/18 21:06:06 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

size_t	ft_printf(const char *format, ...)
{
	int		num;
	size_t	t_len;
	va_list	args;
//	char	*str;

	num = 0;
	t_len = 0;
	va_start(args, format);
	if ((format == ((void *)0) || *format == '%' ) && ((format + 1) != '\0'))
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 's')
				t_len += ft_print_str(format, args);
			if (*format == 'p')
			if (*format == 'd')
				t_len += ft_print_int(num, args);
			if (*format == 'i')
				t_len += ft_print_int(num, args);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
		t_len++;
	}
	va_end(args);
	//printf("%d\n", t_len);
	return (t_len);
}

int	main(void)
{
	int	t_len;

	t_len = ft_printf("Ola %d Porto este e um pequeno teste do %s\n", 42, "David");
	ft_printf("%d\n", ft_strlen("Ola 42 Porto este e um pequeno teste do David\n"));
	ft_printf("%d\n", t_len);
}
