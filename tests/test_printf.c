/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:29:06 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/27 21:06:26 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>
#include <limits.h>

/**
 * @brief Testa e compara ft_printf com printf
 */
int main(void)
{
	int ret_ft;
	int ret_printf;
	int var = 42;
	int *ptr = &var;

	ft_printf("=== TESTES FT_PRINTF ===\n\n");

	// Teste %c - Caractere
	ft_printf("--- Teste %%c (caractere) ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Char: %c\n", 'A');
	
	printf("printf orig: ");
	ret_printf = printf("Char: %c\n", 'A');
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste %s - String
	ft_printf("--- Teste %%s (string) ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("String: %s\n", "Olá, mundo!");
	
	printf("printf orig: ");
	ret_printf = printf("String: %s\n", "Olá, mundo!");
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste %s - String NULL
	ft_printf("--- Teste %%s (NULL) ---\n");
	ft_printf("meu printf:  ");
	
	ret_ft = ft_printf("NULL: %s\n", NULL);
	printf("Retorno ft: %d\n\n", ret_ft);

	//Teste %s - String vazia
	ft_printf("---- Teste %%s (Vazia) ---\n");

	ft_printf("meu printf: {empty}");
	ret_ft = ft_printf("%s\n", "");

	printf("printf orig: {empty}");
	ret_printf = printf("%s\n", "");
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste %p - Ponteiro
	ft_printf("--- Teste %%p (ponteiro) ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Endereço: %p\n", ptr);
	
	printf("printf orig: ");
	ret_printf = printf("Endereço: %p\n", ptr);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste %p - Ponteiro NULL
	ft_printf("--- Teste %%p (NULL) ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("NULL: %p\n", NULL);
	
	printf("printf orig: ");
	ret_printf = printf("NULL: %p\n", NULL);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste %d - Inteiro positivo
	ft_printf("--- Teste %%d (positivo) ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Número: %d\n", 42);
	
	printf("printf orig: ");
	ret_printf = printf("Número: %d\n", 42);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste %d - Inteiro negativo
	ft_printf("--- Teste %%d (negativo) ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Número: %d\n", -42);
	
	printf("printf orig: ");
	ret_printf = printf("Número: %d\n", -42);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste %d - Zero
	ft_printf("--- Teste %%d (zero) ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Zero: %d\n", 0);
	
	printf("printf orig: ");
	ret_printf = printf("Zero: %d\n", 0);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste %i - Inteiro (igual a %d)
	ft_printf("--- Teste %%i (inteiro) ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Inteiro: %i\n", 123);
	
	printf("printf orig: ");
	ret_printf = printf("Inteiro: %i\n", 123);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste %u - Unsigned positivo
	ft_printf("--- Teste %%u (unsigned positivo) ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Unsigned: %u\n", 280);
	
	printf("printf orig: ");
	ret_printf = printf("Unsigned: %u\n", 280);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste %u - Unsigned com número negativo (wrap around) - valor = 2^32 - |Nº negativo| => 4.294.967.296 - 28 = 4.294.967.268
	ft_printf("--- Teste %%u (negativo -> wrap) ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Unsigned: %u\n", -28);
	
	printf("printf orig: ");
	ret_printf = printf("Unsigned: %u\n", -28);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste %x - Hexadecimal minúsculas
	ft_printf("--- Teste %%x (hex minúsculas) ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Hex: %x\n", 255);
	
	printf("printf orig: ");
	ret_printf = printf("Hex: %x\n", 255);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste %X - Hexadecimal maiúsculas
	ft_printf("--- Teste %%X (hex maiúsculas) ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Hex: %X\n", 255);
	
	printf("printf orig: ");
	ret_printf = printf("Hex: %X\n", 255);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste %% - Percentagem
	ft_printf("--- Teste %%%% (percentagem) ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Percentagem: %%\n");
	
	printf("printf orig: ");
	ret_printf = printf("Percentagem: %%\n");
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste Misto - Múltiplas conversões
	ft_printf("--- Teste Misto (várias conversões) ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Mix: %c %s %d %u %x %%\n", 'A', "teste", -42, 100, 255);
	
	printf("printf orig: ");
	ret_printf = printf("Mix: %c %s %d %u %x %%\n", 'A', "teste", -42, 100, 255);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste Limites - INT_MAX e INT_MIN
	ft_printf("--- Teste Limites (INT_MAX e INT_MIN) ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("MAX: %d MIN: %d\n", INT_MAX, INT_MIN);
	
	printf("printf orig: ");
	ret_printf = printf("MAX: %d MIN: %d\n", INT_MAX, INT_MIN);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	ft_printf("=== FIM DOS TESTES ===\n");
	return (0);
}
