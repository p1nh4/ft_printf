/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:35:17 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/07 22:26:04 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_print_ptr_bonus(void *p, t_flags *flags)
{
	unsigned  long int	temp;
	size_t				len;
	void				*ptr_hex;
	int					lower_case;
	int					spaces;

	spaces = 0;
	ptr_hex = (void *)p;
	if (!ptr_hex)
	{
		len = 5;
		if (flags->width > 5)
			spaces = flags->width - len;
		len += spaces;
		if (!flags->minus)
		{
			while (spaces--)
				ft_putchar_fd(' ', 1);
		}
		ft_putstr_fd("(nil)", 1);
		if (flags->minus)
		{
			while(spaces--)
				ft_putchar_fd(' ', 1);
		}
		return (len);
	}
	len = 0;
	lower_case = 1;
	temp = (unsigned long int)p;
	//ft_putchar_fd('0', 1);
	//ft_putchar_fd('x', 1);
	flags->hashtag = 1;
	len += ft_print_hex_bonus(temp, lower_case, flags);
	return (len + 2); 
}
