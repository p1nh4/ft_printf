/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:52:28 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/25 17:16:58 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//(format + 1) nao move o ptr, format++ sim
int	ft_printf(const char *format, ...)
{
	int		t_len;
	va_list	args;

	t_len = 0;
	va_start(args, format);
	if (format == ((void *)0) || *format == '\0'
		|| ((*format == '%') && (*(format + 1) == '\0')))
		return (0);
	while (*format)
	{
		if (*format == '%' && ft_strchr("cspdiuxX%", (*(++format))))
			t_len += ft_process_specifier(*format, args);
		else
		{
			ft_putchar_fd(*format, 1);
			t_len++;
		}
		format++;
	}
	va_end(args);
	return (t_len);
}

/*
int	main(void)
{
	int ret =	printf(" NULL %s NULL \n", NULL);
	printf("%d\n", ret);
	int rot = ft_printf(" NULL %s NULL \n", NULL);
	printf("%d\n", rot);
}
*/
/*
int	main(void)
{
	int ret = ft_printf(" %u ", 101);
	printf("\nReturn: %d\n", ret);

	int ret2 = printf(" %u ", 101);
	printf("\nReturn: %d\n", ret2);

	int r1 = ft_printf(" %u ", 101);
	printf("\nReturn: %d\n", r1);

	int r2 = ft_printf(" %u ", 1001);
	printf("\nReturn: %d\n", r2);

	int r3 = ft_printf(" %u ", 100);
	printf("\nReturn: %d\n", r3);

	int r4 = ft_printf(" %u ", 1000);
	printf("\nReturn: %d\n", r4);

}
*/
/*
int	main(void)
{
	//print numbers and strings
	int	t_len;

	t_len = ft_printf("Ola %d Porto este e um teste do %s\n", 42, "David");
	ft_printf("%d\n", ft_strlen("Ola 42 Porto este e um teste do David\n"));
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
