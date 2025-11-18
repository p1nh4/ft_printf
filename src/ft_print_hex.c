/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:40:46 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/18 22:55:48 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_print_hex(unsigned long int n)
{
	int	len;
	int	temp;
	int	*arr;

	*arr = 0;
	temp = 0;
	if (n == 0)
		return (0);
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			*arr = '0' + temp;
		else
			*arr = '7' + temp;
		n /= 16;
		arr++;
	}
	len = ft_strlen(ft_itoa(arr));
	while (len--)
		ft_putchar_fd(*arr, 1);
	len = ft_strlen(ft_itoa(arr));
	return (len);
}
