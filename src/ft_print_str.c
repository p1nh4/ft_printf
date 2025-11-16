/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:44:29 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/16 18:11:08 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_print_str(const char *s, va_list args)
{
	size_t	len;
	char	*str;

	str = (char *)s;
	str = va_arg(args, char *);
	ft_putstr_fd(str, 1);
	len = ft_strlen(s);
	return (len);
}

/*Usei va_arg para iterar pelos argumentos recebendo da funcao
 * printf o arg passado, logo uso putstr para imprimir a str
 * e conto o tamanho para devolver o mesmo para printf para
 * ter o calculo da string total correto
 */

//como o lenth so retorna 2 e nao 5 para o nome????
