/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:02:00 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/25 16:53:50 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus_utils.h"

int	ft_get_num_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_print_sign(int is_neg, t_flags *flags)
{
	if (is_neg)
		ft_putchar_fd('-', 1);
	else if (flags->plus)
		ft_putchar_fd('+', 1);
	else if (flags->space)
		ft_putchar_fd(' ', 1);
}

void	ft_putnbr_long(long n)
{
	if (n < 0)
		n = -n;
	if (n >= 10)
		ft_putnbr_long(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}
