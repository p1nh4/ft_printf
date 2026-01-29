/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:09:09 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/29 21:46:18 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Extrai os dígitos de um número em ordem reversa.
 * 
 * Esta função auxiliar processa um número long int, extraindo seus dígitos
 * e armazenando-os em ordem reversa. Também conta zeros à direita que precedem
 * os dígitos significativos.
 * 
 * @param num Ptr para o número a ser processado (modificado durante execução)
 * @param len Ponteiro para contador do comprimento total
 * @param zeros Ponteiro para contador de zeros à direita
 * @param reverse Ponteiro para o número com dígitos em ordem reversa
 */

static void	ft_extract_digit(long int *num, int *len,
		int *zeros, long int *reverse)
{
	while (*num > 0)
	{
		if (*num % 10 == 0 && *reverse == 0)
			(*zeros)++;
		else
			*reverse = *reverse * 10 + *num % 10;
		*num /= 10;
		(*len)++;
	}
}

/**
 * @brief Imprime um número long int sem sinal.
 * 
 * Esta função auxiliar converte e imprime um número long int utilizando
 * o algoritmo de reversão de dígitos, garantindo que zeros à direita
 * sejam impressos corretamente.
 * 
 * @param num Número a ser impresso
 * @return Número de caracteres impressos
 */

static size_t	ft_putnbr_u(long int num)
{
	int			len;
	int			zeros;
	long int	reverse;

	len = 0;
	zeros = 0;
	reverse = 0;
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_extract_digit(&num, &len, &zeros, &reverse);
	while (reverse)
	{
		ft_putchar_fd(reverse % 10 + '0', 1);
		reverse /= 10;
	}
	while (zeros--)
		ft_putchar_fd('0', 1);
	return (len);
}

/**
 * @brief Imprime um número inteiro sem sinal.
 * 
 * Esta função converte e imprime um unsigned int, tratando números negativos
 * passados como parâmetro através de wrap-around (ex: -1 vira 4294967295).
 * 
 * Casos especiais:
 * - n == 0: imprime '0' e retorna 1
 * - Números negativos: convertidos automaticamente 
 *   para unsigned (complemento de 2)
 * 
 * @param n Número inteiro sem sinal a ser impresso
 * @return Número de caracteres impressos
 */

size_t	ft_print_uint(const unsigned int n)
{
	size_t			len;

	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	len = ft_putnbr_u(n);
	return (len);
}
