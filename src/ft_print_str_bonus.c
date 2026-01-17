/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:13:19 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/17 00:00:00 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_print_spaces(int count)
{
	while (count-- > 0)
		ft_putchar_fd(' ', 1);
}

static void	ft_print_str_content(char *s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
}

static int	ft_get_str_len(char *s, t_flags *flags)
{
	int	str_len;
	int	len;

	if (!s)
		str_len = 6;
	else
		str_len = ft_strlen(s);
	len = str_len;
	if (flags->precision >= 0 && flags->precision < str_len)
		len = flags->precision;
	return (len);
}

size_t	ft_print_str_bonus(char *s, t_flags *flags)
{
	int		len;
	int		spaces;

	len = ft_get_str_len(s, flags);
	spaces = 0;
	if (flags->width > len)
		spaces = flags->width - len;
	if (!flags->minus)
		ft_print_spaces(spaces);
	if (!s)
		ft_print_str_content("(null)", len);
	else
		ft_print_str_content(s, len);
	if (flags->minus)
		ft_print_spaces(spaces);
	return (len + spaces);
}
