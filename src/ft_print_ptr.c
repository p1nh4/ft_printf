/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:35:17 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/18 22:40:35 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_print_ptr(const void *p, va_list args)
{
	int					i;
	unsigned  long int	temp;
	size_t				len;
	void				*ptr_hex;
	char				*str[sizeof(void *)*2];

	*str = "nil";
	ptr_hex = va_arg(args, void *);
	if (ptr_hex)
	{
		i = 0;
		while (*str)
		{
			ft_putchar_fd(*str, 1);
			str++;
			i++;
		}
		return (i);
	}
	len = 2;
	temp = (unsigned long int)p;
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	
	len += ft_strlen(temp);

	return ();
}
