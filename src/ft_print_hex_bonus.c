/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:13:19 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/25 16:52:33 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_printf_bonus_utils.h"

static int	ft_calc_len_params(unsigned long int n, t_flags *flags,
		int	*n_zeros, int *prefix)
{
	int	n_digits;

	n_digits = ft_hex_len(n);
	if (flags->precision == 0 && n == 0)
		n_digits = 0;
	*n_zeros = 0;
	if (flags->precision > n_digits)
		*n_zeros = flags->precision - n_digits;
	*prefix = 0;
	if (flags->hashtag && n != 0)
		*prefix = 2;
	return (n_digits + *n_zeros + *prefix);
}

static void	ft_do_print_hex(unsigned long int n, int is_lower,
		t_flags *flags, t_print_params p)
{
	if (!flags->minus && (!flags->zeros || flags->precision >= 0))
		ft_print_padding(p.spaces, ' ');
	if (p.prefix)
		ft_print_prefix(is_lower);
	if (!flags->minus && flags->zeros && flags->precision < 0)
		ft_print_padding(p.spaces, '0');
	ft_print_padding(p.n_zeros, '0');
	if (!(flags->precision == 0 && n == 0))
	{
		if (is_lower)
			ft_print_hex_num(n, LOWER_BASE);
		else
			ft_print_hex_num(n, UPPER_BASE);
	}
	if (flags->minus)
		ft_print_padding(p.spaces, ' ');
}

static int	ft_output_hex(unsigned long int n, int is_lower, t_flags *flags)
{
	t_print_params	p;
	int				len;

	len = ft_calc_len_params(n, flags, &p.n_zeros, &p.prefix);
	p.spaces = 0;
	if (flags->width > len)
		p.spaces = flags->width - len;
	len += p.spaces;
	ft_do_print_hex(n, is_lower, flags, p);
	return (len);
}

size_t	ft_print_hex_bonus(unsigned long int n, int is_lower, t_flags *flags)
{
	int		len;

	len = ft_output_hex(n, is_lower, flags);
	return (len);
}
