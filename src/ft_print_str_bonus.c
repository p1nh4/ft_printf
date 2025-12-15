/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:44:29 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/15 23:15:12 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_str_bonus(char *s, t_flags *flags)
{
	size_t	len;
	int		spaces;

	spaces = 0;
	if (!s)
		len = 6;
	else
		len = ft_strlen(s);
	if (flags->width > (int)len)
		spaces = flags->width - len;
	len += spaces;
	if (!flags->minus)
	{
		while (spaces--)
			ft_putchar_fd(' ', 1);
	}
	if (!s)
		ft_putstr_fd("(null)", 1);
	else if (flags->precision >= 0)
	{
		if (flags->precision < (int)len)
			len = flags->precision;
		while (flags->precision-- && *s)
			ft_putchar_fd(*s++, 1);
	}	
	else
		ft_putstr_fd(s, 1);
	if (flags->minus)
	{
		while (spaces--)
			ft_putchar_fd(' ', 1);
	}
	return (len);
}

/*Usei va_arg para iterar pelos argumentos recebendo da funcao
 * printf o arg passado, logo uso putstr para imprimir a str
 * e conto o tamanho para devolver o mesmo para printf para
 * ter o calculo da string total correto
 */

//como o lenth so retorna 2 e nao 5 para o nome????
