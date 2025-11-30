/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:44:29 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/30 19:50:42 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_str(char *s)
{
	size_t	len;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}	

	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	return (len);
}

/*Usei va_arg para iterar pelos argumentos recebendo da funcao
 * printf o arg passado, logo uso putstr para imprimir a str
 * e conto o tamanho para devolver o mesmo para printf para
 * ter o calculo da string total correto
 */

//como o lenth so retorna 2 e nao 5 para o nome????
