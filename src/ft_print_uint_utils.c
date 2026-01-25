/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:16:42 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/25 16:54:02 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus_utils.h"

int	ft_get_uint_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_uint(unsigned int n)
{
	if (n >= 10)
		ft_putnbr_uint(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}
