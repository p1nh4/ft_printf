/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:28:56 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/03 20:20:23 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_int_bonus(int n, t_flags *flags)
{
	size_t	len;
//	int		n_zeros;
	int		spaces;
	char	*str_n;

	str_n = ft_itoa(n);
	len = ft_strlen(str_n);
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
	if (!flags->minus)
	{
		while (spaces--)
			ft_putchar_fd(' ', 1);
	}
	if (flags->plus && n >= 0)
		ft_putchar_fd('+', 1);
	else if (flags->space && n >= 0)
		ft_putchar_fd(' ', 1);
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
