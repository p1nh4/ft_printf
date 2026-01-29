/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:40:46 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/29 21:30:34 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/**
 * @brief Imprime o buffer de dígitos hexadecimais na ordem correta.
 * 
 * Esta função auxiliar imprime os dígitos hexadecimais armazenados em ordem
 * reversa no buffer. Se is_lower for verdadeiro, imprime em minúsculas (a-f),
 * caso contrário, converte para maiúsculas (A-F) usando ft_toupper.
 * 
 * @param buffer Array contendo os dígitos hexadecimais em ordem reversa
 * @param i Número de dígitos no buffer
 * @param is_lower Flag indicando se deve usar minúsculas (1) ou maiúsculas (0)
 */
static void	ft_put_hex_buffer(char buffer[], int i, int is_lower)
{
	if (is_lower)
	{
		while (i--)
			ft_putchar_fd(buffer[i], 1);
	}
	else
	{
		while (i--)
			ft_putchar_fd(ft_toupper(buffer[i]), 1);
	}
}
/**
 * @brief Converte e imprime um número em formato hexadecimal.
 * 
 * Esta função converte um número inteiro sem sinal para sua representação
 * hexadecimal e imprime o resultado. O buffer é dimensionado para suportar
 * sistemas de 32 e 64 bits (sizeof(void *) * 2 + 1) + \0.
 * 
 * Casos especiais:
 * - Se n == 0, imprime '0' e retorna 1
 * 
 * @param n Número a ser convertido para hexadecimal
 * @param is_lower Flag indicando formato: 1 minúsculas (%x), 0 maiúsculas (%X)
 * @return Número de caracteres impressos 
 */

size_t	ft_print_hex(unsigned long int n, int is_lower)
{
	int		digit;
	int		i;
	size_t	len;
	char	*table;
	char	buffer[sizeof(void *) * 2 + 1];

	i = 0;
	table = "0123456789abcdef";
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	while (n)
	{
		digit = n % 16;
		buffer[i] = table[digit];
		i++;
		n /= 16;
	}
	len = i;
	ft_put_hex_buffer(buffer, i, is_lower);
	return (len);
}
