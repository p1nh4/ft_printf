/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:34:16 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/29 21:06:36 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Imprime um único caractere na saída padrão.
 *
 * Esta função recebe um inteiro (que pode ser qualquer valor ASCII) e
 * imprime o caractere correspondente usando ft_putchar_fd.
 *
 * @param c O caractere a ser impresso (passado como int devido a variadic args)
 * @return Sempre retorna 1 (número de caracteres impressos)
 */

size_t	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
