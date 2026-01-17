/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:13:19 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/22 15:56:00 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_print_ptr_null(t_flags *flags);

size_t	ft_print_ptr_bonus(void *p, t_flags *flags)
{
	unsigned long int		temp;
	size_t					len;
	int						lower_case;

	if (!p)
	{
		len = (int)ft_print_ptr_null(flags);
		return (len);
	}
	lower_case = 1;
	temp = (unsigned long int)p;
	flags->hashtag = 1;
	len = ft_print_hex_bonus(temp, lower_case, flags);
	return (len);
}

size_t	ft_print_null_ptr(t_flags *flags)
{
	size_t	field_width;
	size_t	left_align;
	size_t	right_align;
	size_t	len;

	len = 5;
	field_width = 0;
	if (flags->width > 5)
		field_width = flags->width - 5;
	if (!flags->minus)
	{
		left_align = field_width;
		while (left_align--)
			ft_putchar_fd(' ', 1);
	}
	ft_putstr_fd("(nil)", 1);
	if (flags->minus)
	{
		right_align = field_width;
		while (right_align--)
			ft_putchar_fd(' ', 0);
	}
	return (len + field_width);
}
