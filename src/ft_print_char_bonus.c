/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:34:16 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/03 22:55:41 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_char_bonus(int c, t_flags *flags)
{
	int	spaces;
	int	len;

	len = 0;
	if (flags->width > 1)
		spaces = flags->width - 1;
	else
		spaces = 0;
	len += spaces;
	if (!flags->minus)
	{
		while (spaces--)
			ft_putchar_fd(' ', 1);
	}
	ft_putchar_fd(c, 1);
	if (flags->minus)
	{
		while (spaces--)
			ft_putchar_fd(' ', 1);
	}
	return (1 + len);
}
