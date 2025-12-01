/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:40:46 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/01 19:23:00 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_hex_bonus(unsigned long int n, int flag, t_flags *flags)
{
	int		digit;
	int		i;
	size_t	len;
	char	*table;
	char	buffer[sizeof(void *) * 2 + 1]; //array de char ajusta a sistemas 32-64bits + \0

	i = 0;
	len = 0;
	table = "0123456789abcdef";
	if (n == 0)
	{
		if (flags->hashtag == 1 && flag)
		{
			ft_putchar_fd('0', 1);
			ft_putchar_fd('x', 1);
			len += 2;
		}
		else if (flags->hashtag == 1 && !flag)
		{
			ft_putchar_fd('0', 1);
			ft_putchar_fd('X', 1);
			len += 2;
		}
		ft_putchar_fd('0', 1);
		return (1 + len);
	}
	while (n)
	{
		digit = n % 16;
		buffer[i] = table[digit];
		i++;
		n /= 16;
	}
	len = i;
	if (flag)
	{
		if (flags->hashtag == 1)
		{
			len += 2;
			ft_putchar_fd('0', 1);
			ft_putchar_fd('x', 1);
		}
		while (i--)
		{
			ft_putchar_fd(buffer[i], 1);
		}
	}
	else
	{
		if (flags->hashtag == 1)
		{
			len += 2;
			ft_putchar_fd('0', 1);
			ft_putchar_fd('X', 1);
		}
		while (i--)
		{
			ft_putchar_fd(ft_toupper(buffer[i]), 1);
		}
	}
	return (len);
} 
