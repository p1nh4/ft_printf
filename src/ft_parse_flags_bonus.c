/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:39:50 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/30 22:41:57 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_flags_bonus(const char **format, t_flags *flags)
{
 	while (!ft_strchr("cspiuxX%", **format))
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
		(*format)++;
	}
}
