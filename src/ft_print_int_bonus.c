/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:28:56 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/15 20:52:38 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

size_t	ft_print_int_bonus(int n, t_flags *flags)
{
	size_t	len;
	int		n_zeros;
	int		spaces;
	int		n_digits;
	int		is_negative;
	//int		signal;
	char	*str_n;

	n_zeros = 0;
	n_digits = 0;
	is_negative = 0;
	len = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	str_n = ft_itoa(n);
	n_digits = ft_strlen(str_n);
	len = n_digits;
	if (is_negative || flags->plus || flags->space)
		len += 1;
	/*else if (!flags->plus && flags->space && n >= 0)
		len += 1;*/
	if (flags->precision >= 0 && flags->precision > n_digits)
	{
		n_zeros = flags->precision - n_digits;
		len += n_zeros;
	}
	spaces = 0;
	if (flags->width >= (int)len)
	{
		spaces = flags->width - len;
		len += spaces;
	}
	else
		spaces = 0;
	//signal = 0;
	if (!flags->minus)
	{
		if (flags->zeros && flags->precision < 0)
		{
			if (is_negative)
				ft_putchar_fd('-', 1);
			if (flags->plus && n >= 0)
				ft_putchar_fd('+', 1);
			else if (flags->space && n >= 0)
				ft_putchar_fd(' ', 1);
			while (spaces--)
				ft_putchar_fd('0', 1);
		}
		else
		{
			while (spaces--)
		 		ft_putchar_fd(' ', 1);
			if (is_negative)
				ft_putchar_fd('-', 1);
			if (flags->plus && n >= 0)
				ft_putchar_fd('+', 1);
			else if (flags->space && n >= 0)
				ft_putchar_fd(' ', 1);

		}
	}
	else
	{
		if (is_negative)
			ft_putchar_fd('-', 1);
		if (flags->plus && n >= 0)
			ft_putchar_fd('+', 1);
		else if (flags->space && n >= 0)
			ft_putchar_fd(' ', 1);
	}
	if (flags->precision >= 0)
	{
		while (n_zeros--)
			ft_putchar_fd('0', 1);
	}

	ft_putstr_fd(str_n, 1);
 	if (flags->minus)
	{
		while(spaces--)
			ft_putchar_fd(' ', 1);
	}
	free(str_n);
	return (len);
}
/*converto o valor para int, logo iteramo pelos argumentos
 * convertemos esse in a str e logo print da str e enviamos
 * o tamanho da mesma.
 */
