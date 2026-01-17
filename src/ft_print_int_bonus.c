/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:13:19 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/17 00:00:00 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_get_num_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_print_sign(int is_neg, t_flags *flags)
{
	if (is_neg)
		ft_putchar_fd('-', 1);
	else if (flags->plus)
		ft_putchar_fd('+', 1);
	else if (flags->space)
		ft_putchar_fd(' ', 1);
}

static void	ft_print_padding(int count, char c)
{
	while (count-- > 0)
		ft_putchar_fd(c, 1);
}

static void	ft_putnbr_long(long n)
{
	if (n < 0)
		n = -n;
	if (n >= 10)
		ft_putnbr_long(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}

size_t	ft_print_int_bonus(int n, t_flags *flags)
{
	long	num;
	int		n_digits;
	int		n_zeros;
	int		spaces;
	int		len;

	num = n;
	n_digits = ft_get_num_len(num);
	if (flags->precision == 0 && num == 0)
		n_digits = 0;
	n_zeros = 0;
	if (flags->precision > n_digits)
		n_zeros = flags->precision - n_digits;
	len = n_digits + n_zeros;
	if (num < 0 || flags->plus || flags->space)
		len++;
	spaces = 0;
	if (flags->width > len)
		spaces = flags->width - len;
	len += spaces;
	if (!flags->minus && (!flags->zeros || flags->precision >= 0))
		ft_print_padding(spaces, ' ');
	ft_print_sign(num < 0, flags);
	if (!flags->minus && flags->zeros && flags->precision < 0)
		ft_print_padding(spaces, '0');
	ft_print_padding(n_zeros, '0');
	if (!(flags->precision == 0 && num == 0))
		ft_putnbr_long(num);
	if (flags->minus)
		ft_print_padding(spaces, ' ');
	return (len);
}
