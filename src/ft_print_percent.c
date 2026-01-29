/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:47:03 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/29 21:33:29 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Imprime o caractere de percentagem (%).
 * 
 * Esta função é chamada quando o especificador %% é encontrado na string
 * de formato, resultando na impressão de um único caractere '%'.
 * 
 * @param c Caractere a ser impresso (sempre será '%')
 * @return Sempre retorna 1 (número de caracteres impressos)
 */

size_t	ft_print_percent(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
