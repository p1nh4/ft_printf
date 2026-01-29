/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_specifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:28:30 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/29 21:56:32 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Processa um especificador de conversão e imprime o resultado.
 * 
 * Esta função determina qual tipo de conversão executar com base no
 * especificador fornecido, extrai o argumento apropriado da lista variável
 * e chama a função de impressão correspondente.
 * 
 * Especificadores suportados:
 * - %c: caractere (char)
 * - %s: string (char *)
 * - %p: ponteiro (void *)
 * - %d/%i: inteiro com sinal (int)
 * - %u: inteiro sem sinal (unsigned int)
 * - %x: hexadecimal minúsculas (unsigned int)
 * - %X: hexadecimal maiúsculas (unsigned int)
 * - %%: caractere '%' literal
 * 
 * @param format Caractere especificador de conversão
 * @param args Lista de argumentos variáveis
 * @return Número de caracteres impressos pela conversão
 */

size_t	ft_process_specifier(char format, va_list args)
{
	size_t	t_len;

	t_len = 0;
	if (format == 'c')
		t_len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		t_len += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		t_len += ft_print_ptr(va_arg(args, void *));
	else if (format == 'd')
		t_len += ft_print_int(va_arg(args, int));
	else if (format == 'i')
		t_len += ft_print_int(va_arg(args, int));
	else if (format == 'u')
		t_len += ft_print_uint(va_arg(args, unsigned int));
	else if (format == 'x')
		t_len += ft_print_hex(va_arg(args, unsigned int), LOWER_CASE);
	else if (format == 'X')
		t_len += ft_print_hex(va_arg(args, unsigned int), UPPER_CASE);
	else if (format == '%')
		t_len += ft_print_percent('%');
	return (t_len);
}
