/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:09:09 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/21 21:48:02 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h>

size_t	ft_print_uint(const unsigned int ptr)
{
	size_t			len;
	unsigned  int	num;
	unsigned int	num_uint;

	len = 1;
	num_uint = (unsigned int )ptr;

	if (num_uint == 0)
	{
		ft_putchar_fd(0 + '0', 1);
		return (1);
	}
	num = num_uint;
	/*while (num > 0)
	{
		num /= 10;
		len++;
	}*/
	//printf("%u----------", num_uint);
	ft_print_num_rev(num_uint);
	return (len);
}
/*
void	print_num_rec(int n)
{
	unsigned int	num;
	int				reverse;

	reverse = 0;
	while (num--)
	{
		reverse = reverse * 10 + num % 10;
		ft_putchar_fd(reverse + '0', 1);
		n /= 10;
	}
}*/
