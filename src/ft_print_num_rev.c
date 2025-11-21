/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_rev.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:30:40 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/21 22:02:05 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_num_rev(long int num)
{
	long int	reverse;

	reverse = 0;
	while (num > 0)
	{
		reverse = reverse * 10 + num % 10;
		num /= 10;
	}

	while (reverse > 0)
	{
		ft_putchar_fd(reverse % 10 + '0', 1);
		reverse /= 10;
	}
}
