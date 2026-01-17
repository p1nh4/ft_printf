/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:09:09 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/17 22:26:04 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:13:19 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/17 00:00:00 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_get_uint_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_print_padding(int count, char c)
{
	while (count-- > 0)
		ft_putchar_fd(c, 1);
}

static void	ft_putnbr_uint(unsigned int n)
{
	if (n >= 10)
		ft_putnbr_uint(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}

size_t	ft_print_uint_bonus(unsigned int n, t_flags *flags)
{
	int	n_digits;
	int	n_zeros;
	int	spaces;
	int	len;

	n_digits = ft_get_uint_len(n);
	if (flags->precision == 0 && n == 0)
		n_digits = 0;
	n_zeros = 0;
	if (flags->precision > n_digits)
		n_zeros = flags->precision - n_digits;
	len = n_digits + n_zeros;
	spaces = 0;
	if (flags->width > len)
		spaces = flags->width - len;
	len += spaces;
	if (!flags->minus && (!flags->zeros || flags->precision >= 0))
		ft_print_padding(spaces, ' ');
	if (!flags->minus && flags->zeros && flags->precision < 0)
		ft_print_padding(spaces, '0');
	ft_print_padding(n_zeros, '0');
	if (!(flags->precision == 0 && n == 0))
		ft_putnbr_uint(n);
	if (flags->minus)
		ft_print_padding(spaces, ' ');
	return (len);
}

/*
#include "ft_printf_bonus.h"

size_t	ft_print_uint_bonus(unsigned int n, t_flags *flags)
{
	size_t			len;
	int				spaces;
	int				n_zeros;

	len = ft_len_uint(n);
	spaces = 0;
	n_zeros = 0;
	if (flags->precision >= 0 && flags->precision > (int)len)
		n_zeros = flags->precision - len;
	len += n_zeros;
	if (flags->width >= (int)len)
		spaces = flags->width - len;
	len += spaces;
	if (!flags->minus)
	{
		if (flags->zeros && flags->precision < 0)
		{
			while (spaces--)
				ft_putchar_fd('0', 1);
		}
		else
		{
			while (spaces--)
				ft_putchar_fd(' ', 1);
		}
	}
	if (flags->precision >= 0)
	{
		while (n_zeros--)
			ft_putchar_fd('0', 1);
	}
	ft_print_num_rev(n);
	if (flags->minus)
	{
		while (spaces--)
			ft_putchar_fd(' ', 1);
	}
	return (len);
}
*/
/*
void	print_num_rec(int n)
{
	unsigned int	num;
	int				reverse;

	reverse = 0;
	while (num--)
	{
		reverse = reverse * 10 + num % 10;
		ft_putchar_fd(reverse + '0', 1);
		n /= 10;
	}
}*/
