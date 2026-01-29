/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:35:17 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/29 21:34:55 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Imprime um endereço de ponteiro em formato hexadecimal.
 * 
 * Esta função imprime um endereço de memória no formato "0x..." em hexadecimal
 * minúsculo. Trata ponteiros NULL imprimindo "(nil)".
 * 
 * Formato de saída:
 * - Ponteiro válido: "0x" seguido do endereço em hexadecimal
 * - Ponteiro NULL: "(nil)"
 * 
 * @param p Ponteiro cujo endereço será impresso
 * @return Número de caracteres impressos (5 p/ NULL, len+2 p/ ptrs válidos)
 */

size_t	ft_print_ptr(void *p)
{
	unsigned long int	temp;
	size_t				len;

	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	len = 0;
	temp = (unsigned long int)p;
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	len += ft_print_hex(temp, LOWER_CASE);
	return (len + 2);
}
