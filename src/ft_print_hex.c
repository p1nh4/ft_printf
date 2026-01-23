/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:40:46 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/23 19:34:58 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_hex_buffer(char buffer[], int i, int is_lower)
{
	if (is_lower)
	{
		while (i--)
			ft_putchar_fd(buffer[i], 1);
	}
	else
	{
		while (i--)
			ft_putchar_fd(ft_toupper(buffer[i]), 1);
	}
}

//array de char ajusta a sistemas 32-64bits + \0
size_t	ft_print_hex(unsigned long int n, int is_lower)
{
	int		digit;
	int		i;
	size_t	len;
	char	*table;
	char	buffer[sizeof(void *) * 2 + 1];

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
	ft_print_hex_buffer(buffer, i, is_lower);
	return (len);
}
