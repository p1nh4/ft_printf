/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:13:19 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/20 16:29:23 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

//imprime o char com largura, sendo spaces antes ou depois se tiver
size_t	ft_print_char_bonus(int c, t_flags *flags)
{
	int	field_width;
	int	left_align;
	int	right_align;

	if (flags->width > 1)
		field_width = flags->width - 1;
	else
		field_width = 0;
	if (!flags->minus)
	{
		left_align = field_width;
		while (left_align--)
			ft_putchar_fd(' ', 1);
	}
	ft_putchar_fd(c, 1);
	if (flags->minus)
	{
		right_align = field_width;
		while (right_align--)
			ft_putchar_fd(' ', 1);
	}
	return (1 + field_width);
}
