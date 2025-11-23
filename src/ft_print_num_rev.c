/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_rev.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:30:40 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/23 15:47:14 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_num_rev(long int num)
{
	int			zeros;
	long int	reverse;

	zeros = 0;
	reverse = 0;
	while (num > 0)
	{
		if (num % 10 == 0)
			zeros++;
		else
			reverse = reverse * 10 + num % 10;
		num /= 10;
	}

	while (reverse)
	{
		ft_putchar_fd(reverse % 10 + '0', 1);
		reverse /= 10;
	}
	while (zeros--)
		ft_putchar_fd('0', 1);
}
