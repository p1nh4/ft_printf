/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:28:56 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/13 17:38:29 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
size_t	ft_print_int_bonus(int n, t_flags *flags)
{
	printf("[DEBUG: n=%d, precision=%d, width=%d]\n", n, flags->precision, flags->width);
	size_t	len;
	int		n_zeros;
	int		spaces;
	int		n_digits;
	char	*str_n;

	n_zeros = 0;
	n_digits = 0;
	str_n = ft_itoa(n);
	len = ft_strlen(str_n);
	n_digits = ft_strlen(str_n);
	if (n < 0)
		n_digits--;
	if (flags->plus && n >= 0)
		len += 1;
	else if (!flags->plus && flags->space && n >= 0)
		len += 1;
	/*if (flags->plus == 1 && n >= 0)
	{
		len += 1;
		ft_putchar_fd('+', 1);
	}
	else if (flags->space == 1 && n >= 0 && flags->plus == 0)
	{
		len += 1;
		ft_putchar_fd(' ', 1);
	}
	str_n = ft_itoa(n);*/
	spaces = 0;
	if (flags->width >= (int)len)
	{
		spaces = flags->width - len;
		len += spaces;
	}
	else
		spaces = 0;
/*	if (flags->zeros)
	{
		n_zeros = flags->width - len;
		spaces -= n_zeros;
	}
*/
	if (!flags->minus)
	{
		if (flags->zeros)
		{
			while (spaces--)
				ft_putchar_fd('0', 1);
		}
		else
		{
			while (spaces--)
		 		ft_putchar_fd(' ', 1);
		}	
	}
	if (flags->plus && n >= 0)
		ft_putchar_fd('+', 1);
	else if (flags->space && n >= 0)
		ft_putchar_fd(' ', 1);
	if (flags->precision)
	{
		if (flags->precision > n_digits)
			n_zeros = flags->precision - n_digits;
		while (n_zeros--)
			ft_putchar_fd('0', 1);
	}
	ft_putstr_fd(str_n, 1);
 	if (flags->minus)
	{
		while(spaces--)
			ft_putchar_fd(' ', 1);
	}
	/*n_zeros = 0;
		while (n_zeros--)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str_n, 1);
	len += ft_strlen(str_n);*/

	free(str_n);
	return (len);
}
/*converto o valor para int, logo iteramo pelos argumentos
 * convertemos esse in a str e logo print da str e enviamos
 * o tamanho da mesma.
 */
