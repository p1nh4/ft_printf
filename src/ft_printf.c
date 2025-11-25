/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:52:28 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/25 12:49:18 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t	ft_printf(const char *format, ...)
{
	int		num;
	size_t	t_len;
	va_list	args;
//	char	*str;
	int		lower_case;
	int		upper_case;

	num = 0;
	t_len = 0;
	lower_case = 1;
	upper_case = 0;
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
				t_len += ft_print_ptr(va_arg(args, void *));
			if (*format == 'd')
				t_len += ft_print_int(num, args);
			if (*format == 'i')
				t_len += ft_print_int(num, args);
			if (*format == 'u')
				t_len += ft_print_uint(va_arg(args, unsigned int));
			if (*format == 'x')
				t_len += ft_print_hex(va_arg(args, unsigned int), lower_case);
			if (*format == 'X')
				t_len += ft_print_hex(va_arg(args, unsigned int), upper_case);
			if (*format == '%')
				t_len += ft_print_percent('%');
		}
		else 
		{
			ft_putchar_fd(*format, 1);
			format++;
		}
	//t_len++;
	}
	va_end(args);
	//printf("%d\n", t_len);
	return (t_len);
}
/*
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

	//print unsigned int
	int	u_len;

	u_len = ft_printf("Este e um numero positivo 28: %u\n", 280);
	ft_printf("Tamanho numero positivo: %d\n", u_len);

	u_len = ft_printf("Este e um numero negativo -28 (4294967268): %u\n", -28);
	ft_printf("Tamanho numero negativo: %d\n", u_len);

	//print hexadecimal minusculas
	int	hex_len;
	hex_len = 0;
	hex_len = ft_printf("Este é 255 em  hexadecimal (minusculas): %x\n", 255);
	ft_printf("Tamanho numero hex minusculas: %d\n", hex_len);

	//print hexadecimal maiusculas
	hex_len = 0;
	hex_len = ft_printf("Este é 255 em hexadecimal (maisculas): %X\n", 255);
	ft_printf("Tamanho numero hex maiusculas: %d\n", hex_len);

	//print sinal %
	int	percent_len;
	percent_len = 0;
	percent_len = ft_printf("Este e o sinal %% e aqui igual %%\n");
	ft_printf("Tamanho: %d\n",percent_len);
}*/
