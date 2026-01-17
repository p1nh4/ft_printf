/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:13:19 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/17 00:00:00 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_hex_len(unsigned long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	ft_print_padding(int count, char c)
{
	while (count-- > 0)
		ft_putchar_fd(c, 1);
}

static void	ft_print_hex_num(unsigned long int n, char *base)
{
	if (n >= 16)
		ft_print_hex_num(n / 16, base);
	ft_putchar_fd(base[n % 16], 1);
}

static void	ft_print_prefix(int is_lower)
{
	ft_putchar_fd('0', 1);
	if (is_lower)
		ft_putchar_fd('x', 1);
	else
		ft_putchar_fd('X', 1);
}

size_t	ft_print_hex_bonus(unsigned long int n, int is_lower, t_flags *flags)
{
	int		n_digits;
	int		n_zeros;
	int		spaces;
	int		len;
	int		prefix;
	char	*base;

	if (is_lower)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	n_digits = ft_hex_len(n);
	if (flags->precision == 0 && n == 0)
		n_digits = 0;
	n_zeros = 0;
	if (flags->precision > n_digits)
		n_zeros = flags->precision - n_digits;
	prefix = 0;
	if (flags->hashtag && n != 0)
		prefix = 2;
	len = n_digits + n_zeros + prefix;
	spaces = 0;
	if (flags->width > len)
		spaces = flags->width - len;
	len += spaces;
	if (!flags->minus && (!flags->zeros || flags->precision >= 0))
		ft_print_padding(spaces, ' ');
	if (prefix)
		ft_print_prefix(is_lower);
	if (!flags->minus && flags->zeros && flags->precision < 0)
		ft_print_padding(spaces, '0');
	ft_print_padding(n_zeros, '0');
	if (!(flags->precision == 0 && n == 0))
		ft_print_hex_num(n, base);
	if (flags->minus)
		ft_print_padding(spaces, ' ');
	return (len);
}
