/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:13:19 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/17 00:00:00 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_print_char_bonus(int c, t_flags *flags)
{
	int	spaces;
	int	i;

	spaces = 0;
	if (flags->width > 1)
		spaces = flags->width - 1;
	if (!flags->minus)
	{
		i = spaces;
		while (i-- > 0)
			ft_putchar_fd(' ', 1);
	}
	ft_putchar_fd(c, 1);
	if (flags->minus)
	{
		i = spaces;
		while (i-- > 0)
			ft_putchar_fd(' ', 1);
	}
	return (1 + spaces);
}
