/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:52:28 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/29 21:12:33 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Processa a string de formato e imprime os resultados.
 * 
 * Esta função auxiliar percorre a string de formato caractere por caractere.
 * Quando encontra um '%', verifica se o próximo caractere é um especificador
 * válido (cspdiuxX%) e processa a conversão correspondente. Caso contrário,
 * imprime o caractere literal.
 * 
 * @param format Ponteiro duplo para a string de formato (permite modificação)
 * @param args Lista de argumentos variáveis
 * @return Número total de caracteres impressos, ou -1 em caso de erro
*/
//(format + 1) nao move o ptr, format++ sim
static int	ft_process_format(const char **format, va_list args)
{
	int	t_len;

	t_len = 0;
	while (**format)
	{
		if (**format == '%')
		{
			(*format)++;
			if (!**format || !ft_strchr("cspdiuxX%", **format))
				return (-1);
			t_len += ft_process_specifier(**format, args);
		}
		else
		{
			ft_putchar_fd(**format, 1);
			t_len++;
		}
		(*format)++;
	}
	return (t_len);
}

/**
 * @brief Implementação personalizada da função printf.
 * 
 * Esta função replica o comportamento básico do printf() da biblioteca padrão C.
 * Aceita uma string de formato e um número variável de argumentos, processando
 * os especificadores de conversão suportados: 
 *	%c, %s, %p, %d, %i, %u, %x, %X, %%.
 * 
 * Tratamento de erros:
 * - Retorna -1 se format for NULL
 * - Retorna -1 se houver um '%' seguido de caractere inválido ou fim da string
 * 
 * @param format String de formato contendo texto e especificadores de conversão
 * @param ... Argumentos variáveis correspondentes aos especificadores
 * @return Número total de caracteres impressos, ou -1 em caso de erro

*/
int	ft_printf(const char *format, ...)
{
	int		t_len;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	t_len = ft_process_format(&format, args);
	va_end(args);
	if (t_len == -1)
		return (-1);
	return (t_len);
}
