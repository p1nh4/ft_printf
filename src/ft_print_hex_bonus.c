/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:40:46 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/07 21:34:42 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_hex_bonus(unsigned long int n, int is_lower, t_flags *flags)
{
	int		digit;
	int		i;
	int		spaces;
	size_t	len;
	char	*table;
	char	buffer[sizeof(void *) * 2 + 1]; //array de char ajusta a sistemas 32-64bits + \0

	i = 0;
	len = 0;
	spaces = 0;
	table = "0123456789abcdef";
	if (n == 0)
	{
		if (flags->width > 1)
		{
			spaces = flags->width - 1;
			len += spaces;
		}
		if (!flags->minus)
		{
			while (spaces--)
				ft_putchar_fd(' ', 1);
		}
		/*if (flags->hashtag == 1 && flag)
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
		}*/
		ft_putchar_fd('0', 1);	
		if (flags->minus)
		{
			ft_putchar_fd(' ', 1);
		}
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
	if (flags->hashtag)
			len += 2;	
	if (flags->width > (int)len)
	{
	spaces = flags->width - len;
		len += spaces;
	}
	if (is_lower)
	{
		if (!flags->minus)
		{
			while (spaces--)
				ft_putchar_fd(' ', 1);
		}
		if (flags->hashtag == 1)
		{
			ft_putchar_fd('0', 1);
			ft_putchar_fd('x', 1);
		}
		while (i--)
		{
			ft_putchar_fd(buffer[i], 1);
		}
		if (flags->minus)
		{
			while (spaces--)
				ft_putchar_fd(' ', 1);
		}
	}
	else
	{
		if (!flags->minus)
		{
			while (spaces--)
				ft_putchar_fd(' ', 1);
		}
		if (flags->hashtag == 1)
		{
			ft_putchar_fd('0', 1);
			ft_putchar_fd('X', 1);
		}
		while (i--)
		{
			ft_putchar_fd(ft_toupper(buffer[i]), 1);
		}
		if (flags->minus)
		{
			while (spaces--)
				ft_putchar_fd(' ', 1);
		}
	}
	return (len);
}
