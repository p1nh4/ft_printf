/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:09:09 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/27 18:43:32 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_extract_digit(long int *num, int *len,
		int *zeros, long int *reverse)
{
	while (*num > 0)
	{
		if (*num % 10 == 0 && *reverse == 0)
			(*zeros)++;
		else
			*reverse = *reverse * 10 + *num % 10;
		*num /= 10;
		(*len)++;
	}
}

static size_t	ft_putnbr_printf(long int num)
{
	int			len;
	int			zeros;
	long int	reverse;

	len = 0;
	zeros = 0;
	reverse = 0;
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_extract_digit(&num, &len, &zeros, &reverse);
	while (reverse)
	{
		ft_putchar_fd(reverse % 10 + '0', 1);
		reverse /= 10;
	}
	while (zeros--)
		ft_putchar_fd('0', 1);
	return (len);
}

size_t	ft_print_uint(const unsigned int ptr)
{
	size_t			len;

	if (ptr == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	len = ft_putnbr_printf(ptr);
	return (len);
}
