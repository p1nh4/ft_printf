/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:39:50 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/17 22:22:54 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:13:19 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/17 00:00:00 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_parse_width(const char **format, t_flags *flags)
{
	flags->width = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
}

static void	ft_parse_precision(const char **format, t_flags *flags)
{
	(*format)++;
	flags->precision = 0;
	if (ft_isdigit(**format))
	{
		flags->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

static int	ft_parse_flag_char(const char **format, t_flags *flags)
{
	if (**format == '-')
		flags->minus = 1;
	else if (**format == '0' && flags->width == 0 && !flags->minus)
		flags->zeros = 1;
	else if (**format == '#')
		flags->hashtag = 1;
	else if (**format == '+')
		flags->plus = 1;
	else if (**format == ' ')
		flags->space = 1;
	else
		return (0);
	return (1);
}

void	ft_parse_flags_bonus(const char **format, t_flags *flags)
{
	while (**format && !ft_strchr("cspdiuxX%", **format))
	{
		if (**format == '.')
		{
			ft_parse_precision(format, flags);
			continue ;
		}
		if (ft_isdigit(**format) && **format != '0')
		{
			ft_parse_width(format, flags);
			continue ;
		}
		if (!ft_parse_flag_char(format, flags))
		{
			(*format)++;
			continue ;
		}
		(*format)++;
	}
}


/*
 * #include "ft_printf_bonus.h"

void	ft_parse_flags_bonus(const char **format, t_flags *flags)
{
	while (!ft_strchr("cspdiuxX%", **format))
	{
		if (**format == '-')
			flags->minus = 1;
		else if (**format == '0' && flags->width == 0) //!ft_isdigit(*(*format + 1)))
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
		if (ft_isdigit(**format))
		{
			flags->width = ft_atoi(*format);
			while (ft_isdigit(**format))
			(*format)++;
			continue;
		}
		(*format)++;
	}
}
*/
