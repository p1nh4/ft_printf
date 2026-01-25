/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:13:19 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/25 16:55:23 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_printf_bonus_utils.h"

static	int	ft_calc_int_params(long num, t_flags *flags, t_print_params *p)
{
	int	n_digits;
	int	len;

	n_digits = ft_get_num_len(num);
	if (flags->precision == 0 && num == 0)
		n_digits = 0;
	p->n_zeros = 0;
	if (flags->precision > n_digits)
		p->n_zeros = flags->precision - n_digits;
	len = n_digits + p->n_zeros;
	if (num < 0 || flags->plus || flags->space)
		len++;
	p->spaces = 0;
	if (flags->width > len)
		p->spaces = flags->width - len;
	return (len + p->spaces);
}

static void	ft_do_print_int(long num, t_flags *flags, t_print_params p)
{
	if (!flags->minus && (!flags->zeros || flags->precision >= 0))
		ft_print_padding(p.spaces, ' ');
	ft_print_sign(num < 0, flags);
	if (!flags->minus && flags->zeros && flags->precision < 0)
		ft_print_padding(p.spaces, '0');
	ft_print_padding(p.n_zeros, '0');
	if (!(flags->precision == 0 && num == 0))
		ft_putnbr_long(num);
	if (flags->minus)
		ft_print_padding(p.spaces, ' ');
}

size_t	ft_print_int_bonus(int n, t_flags *flags)
{
	t_print_params	p;
	long			num;
	int				len;

	num = n;
	len = ft_calc_int_params(num, flags, &p);
	ft_do_print_int(num, flags, p);
	return (len);
}
