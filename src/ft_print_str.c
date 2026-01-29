/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:44:29 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/29 21:36:06 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Imprime uma string de caracteres.
 * 
 * Esta função imprime uma string terminada em null. Se o ponteiro for NULL,
 * imprime "(null)" em vez de causar segmentation fault, seguindo o 
 * comportamento de algumas implementações de printf.
 * 
 * Tratamento de casos especiais:
 * - String NULL: imprime "(null)" e retorna 6
 * - String vazia: imprime nada e retorna 0
 * - String normal: imprime o conteúdo e retorna o comprimento
 * 
 * @param s Ponteiro para a string a ser impressa
 * @return Número de caracteres impressos
 */

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
