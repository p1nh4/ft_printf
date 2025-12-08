/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:09:09 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/08 16:44:09 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

#include <stdio.h>

size_t	ft_print_uint_bonus(unsigned int n, t_flags *flags)
{
	size_t			len;
	int				spaces;

	len = ft_len_uint(n);
	spaces = 0;
	if (flags->width >= (int)len)
		spaces = flags->width - len;
	len += spaces;
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
	ft_print_num_rev(n);
	if (flags->minus)
	{
		while (spaces--)
			ft_putchar_fd(' ', 1);
	}
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
