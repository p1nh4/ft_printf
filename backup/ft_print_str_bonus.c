/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:13:19 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/20 16:28:11 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_get_strlen(char *s, t_flags *flags);
void	ft_print_spaces(int spaces);
void	ft_print_str(char *s, int len);

//imprime a str com a largura, os spaces antes ou depois se tiver
size_t	ft_print_str_bonus(char *s, t_flags *flags)
{
	size_t	len;
	int		spaces;

	spaces = 0;
	len = ft_get_strlen(s, flags);
	if (flags->width > (int)len)
		spaces = flags->width - len;
	if (!flags->minus)
		ft_print_spaces(spaces);
	if (!s)
		ft_putstr_fd("(null)", 1);
	else
		ft_print_str(s, len);
	if (flags->minus)
		ft_print_spaces(spaces);
	return (len + spaces);
}

//vef. caso tamanho seja (null), ou precisao seja menor que o len
size_t	ft_get_strlen(char *s, t_flags *flags)
{
	size_t	len;
	size_t	str_len;

	if (!s)
		str_len = 6;
	else
		str_len = ft_strlen(s);
	len = str_len;
	if (flags->precision >= 0 && flags->precision < (int)str_len)
		len = flags->precision;
	return (len);
}

//printar espaços
void	ft_print_spaces(int spaces)
{
	while (spaces--)
		ft_putchar_fd(' ', 1);
}

//imprime a str
void	ft_print_str(char *s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
}
/*Usei va_arg para iterar pelos argumentos recebendo da funcao
 * printf o arg passado, logo uso putstr para imprimir a str
 * e conto o tamanho para devolver o mesmo para printf para
 * ter o calculo da string total correto
 */
