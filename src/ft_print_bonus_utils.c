/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:38:36 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/25 16:18:21 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus_utils.h"

void	ft_print_padding(int count, char c)
{
	while (count-- > 0)
		ft_putchar_fd(c, 1);
}
