/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:28:56 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/01 19:19:57 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_int_bonus(int n, t_flags *flags)
{
	size_t	len;
	int		n_zeros;
	char	*str_n;

	len = 0;
	if (flags->plus == 1 && n >= 0)
	{
		len += 1;
		ft_putchar_fd('+', 1);
	}
	else if (flags->space == 1 && n >= 0 && flags->plus == 0)
	{
		len += 1;
		ft_putchar_fd(' ', 1);
	}
	str_n = ft_itoa(n);
	n_zeros = 0;
	/*if ((int)ft_strlen(str_n) < flags->precision)
		n_zeros = flags->precision - ft_strlen(str_n);
	len += n_zeros;*/
	while (n_zeros--)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str_n, 1);
	len += ft_strlen(str_n);
	free(str_n);
	return (len);
}
/*converto o valor para int, logo iteramo pelos argumentos
 * convertemos esse in a str e logo print da str e enviamos
 * o tamanho da mesma.
 */
