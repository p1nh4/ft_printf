/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:35:17 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/27 18:42:12 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_ptr(void *p)
{
	unsigned long int	temp;
	size_t				len;

	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	len = 0;
	temp = (unsigned long int)p;
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	len += ft_print_hex(temp, LOWER_CASE);
	return (len + 2);
}
