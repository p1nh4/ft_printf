/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:52:38 by davidos-          #+#    #+#             */
/*   Updated: 2025/10/30 22:58:25 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(int fd, char num)
{
	write(fd, &num, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	num;
	char	n_digits[10];

	i = 0;
	num = n;
	if (num == 0)
		ft_putchar(fd, '0');
	else if (num < 0)
	{
		ft_putchar(fd, '-');
		num *= -1;
	}
	while (num > 0)
	{
		n_digits[i] = num % 10 + '0';
		i++;
		num /= 10;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(fd, n_digits[i]);
		i--;
	}
}
