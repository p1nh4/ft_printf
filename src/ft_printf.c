/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:52:28 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/19 23:01:32 by davidos-         ###   ########.fr       */
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
	if (format == ((void *)0))
		return (-1);
	if (*format == '\0')
		return (-1);
	if (*format == '%' || (*(format + 1) == '\0'))
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 's')
				t_len += ft_print_str(format, args);
			if (*format == 'p')
				t_len += ft_print_ptr(format, args);
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
	//print numbers and strings
	int	t_len;

	t_len = ft_printf("Ola %d Porto este e um pequeno teste do %s\n", 42, "David");
	ft_printf("%d\n", ft_strlen("Ola 42 Porto este e um pequeno teste do David\n"));
	ft_printf("%d\n", t_len);
	
	//print ptr (void *)
	int	var;
	int	*ptr_var;
	int	p_len;
	
	var = 10;
	ptr_var = &var;

	p_len = ft_printf("Este e o endereço de memoria: %p de %d\n", ptr_var, var);
	ft_printf("%d\n", p_len);

}
