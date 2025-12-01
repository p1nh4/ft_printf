/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:47:03 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/01 14:43:48 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_percent_bonus(char c)
{
	int	len;

	len = 0;
	ft_putchar_fd(c, 1);
	len += 1;
	return (len);
}
