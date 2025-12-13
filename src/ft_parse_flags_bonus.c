/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:39:50 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/13 17:47:02 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_parse_flags_bonus(const char **format, t_flags *flags)
{
	while ((!ft_strchr("cspdiuxX", **format)) && (!ft_isdigit(**format) || **format == '0'))
	{
		if (**format == '-')
			flags->minus = 1;
		else if (**format == '0')
			flags->zeros = 1;
		else if (**format == '#')
			flags->hashtag = 1;
		else if (**format == '+')
			flags->plus = 1;
		else if (**format == ' ')
			flags->space = 1;
		else if (**format == '.')
		{
			(*format)++;
			flags->precision = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
			continue;
		}	
		(*format)++;
	}
	if (ft_isdigit(**format))
	{
		flags->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}
