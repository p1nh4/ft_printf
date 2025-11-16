/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:28:56 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/16 18:12:14 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_print_int(const int n, va_list args)
{
	size_t	len;
	int		value;
	char	*str_n;

	value = (int)n;
	value = va_arg(args, int);
	str_n = ft_itoa(value);
	ft_putstr_fd(str_n, 1);
	len = ft_strlen(str_n);
	return (len);
}
/*converto o valor para int, logo iteramo pelos argumentos
 * convertemos esse in a str e logo print da str e enviamos
 * o tamanho da mesma.
 */
