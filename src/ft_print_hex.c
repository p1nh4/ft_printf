/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:40:46 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/27 21:43:35 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_print_hex(unsigned long int n, int flag)
{
	int		digit;
	int		i;
	size_t	len;
	char	*table;
	char	buffer[sizeof(void *) * 2 + 1]; //array de char ajusta a sistemas 32-64bits + \0

	i = 0;
	table = "0123456789abcdef";
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
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
		while (i--)
		{
			ft_putchar_fd(buffer[i], 1);
		}
	}
	else
	{
		while (i--)
		{
			ft_putchar_fd(ft_toupper(buffer[i]), 1);
		}
	}
	return (len);
}
