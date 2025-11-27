/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:35:17 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/27 21:44:12 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_print_ptr(void *p)
{
	unsigned  long int	temp;
	size_t				len;
	void				*ptr_hex;
	int					lower_case;

	ptr_hex = (void *)p;
	if (!ptr_hex)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	len = 0;
	lower_case = 1;
	temp = (unsigned long int)p;
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	len += ft_print_hex(temp, lower_case);
	return (len + 2);
}
