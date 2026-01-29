/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:28:56 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/29 21:32:48 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Converte e imprime um número inteiro.
 * 
 * Esta função utiliza ft_itoa para converter o número inteiro em string,
 * imprime o resultado e libera a memória alocada. Suporta números negativos
 * e positivos, incluindo INT_MIN e INT_MAX.
 * 
 * Gestão de memória:
 * - Aloca memória dinamicamente via ft_itoa
 * - Verifica se malloc falhou (retorna 0 em caso de erro)
 * - Libera a memória após impressão
 * 
 * @param n Número inteiro a ser impresso
 * @return Número de caracteres impressos, ou 0 em caso de falha de alocação
 */

size_t	ft_print_int(int n)
{
	size_t	len;
	char	*str_n;

	str_n = ft_itoa(n);
	if (!str_n)
		return (0);
	ft_putstr_fd(str_n, 1);
	len = ft_strlen(str_n);
	free(str_n);
	return (len);
}
