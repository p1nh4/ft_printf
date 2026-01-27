/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_casos_especiais.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:00:00 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/27 21:48:39 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>
#include <limits.h>

/**
 * @brief Testa casos especiais e edge cases do ft_printf
 */
int	main(void)
{
	int	ret_ft;
	int	ret_printf;

	ft_printf("=== TESTES DE CASOS ESPECIAIS ===\n\n");

	/* ========== TESTES DE LIMITES NUMÉRICOS ========== */

	// Teste UINT_MAX
	ft_printf("--- Teste UINT_MAX ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("UINT_MAX: %u\n", UINT_MAX);
	printf("printf orig: ");
	ret_printf = printf("UINT_MAX: %u\n", UINT_MAX);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste -1 em diferentes conversões
	ft_printf("--- Teste -1 em várias bases ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("-1: %%d=%d %%u=%u %%x=%x %%X=%X\n", -1, -1, -1, -1);
	printf("printf orig: ");
	ret_printf = printf("-1: %%d=%d %%u=%u %%x=%x %%X=%X\n", -1, -1, -1, -1);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste hex de números grandes
	ft_printf("--- Teste Hex de números grandes ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Hex max: %x %X\n", UINT_MAX, UINT_MAX);
	printf("printf orig: ");
	ret_printf = printf("Hex max: %x %X\n", UINT_MAX, UINT_MAX);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste LONG_MIN como int (truncado)
	ft_printf("--- Teste truncamento ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Truncado: %d\n", (int)LONG_MIN);
	printf("printf orig: ");
	ret_printf = printf("Truncado: %d\n", (int)LONG_MIN);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	/* ========== TESTES DE ZEROS ========== */

	// Teste zeros em todas as bases
	ft_printf("--- Teste zeros em todas bases ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Zeros: %%d=%d %%u=%u %%x=%x %%X=%X\n", 0, 0, 0, 0);
	printf("printf orig: ");
	ret_printf = printf("Zeros: %%d=%d %%u=%u %%x=%x %%X=%X\n", 0, 0, 0, 0);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste ponteiro zero
	ft_printf("--- Teste ponteiro 0x0 ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Ptr 0x0: %p\n", (void *)0);
	printf("printf orig: ");
	ret_printf = printf("Ptr 0x0: %p\n", (void *)0);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	/* ========== TESTES DE CARACTERES ESPECIAIS ========== */

	// Teste char nulo (invisível mas válido)
	ft_printf("--- Teste char nulo ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Char nulo: '%c' fim\n", '\0');
	printf("printf orig: ");
	ret_printf = printf("Char nulo: '%c' fim\n", '\0');
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste tab e newline
	ft_printf("--- Teste tab e newline ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Tab:\t%c\nNova linha\n", 'X');
	printf("printf orig: ");
	ret_printf = printf("Tab:\t%c\nNova linha\n", 'X');
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste caracteres ASCII baixos
	ft_printf("--- Teste ASCII baixo ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("ASCII: %c %c %c\n", 1, 2, 3);
	printf("printf orig: ");
	ret_printf = printf("ASCII: %c %c %c\n", 1, 2, 3);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	/* ========== TESTES DE PONTEIROS ESPECIAIS ========== */

	// Teste endereço muito grande
	ft_printf("--- Teste ponteiro extremo ---\n");
	void	*big_ptr = (void *)0xFFFFFFFFFFFFFFFF;
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Big ptr: %p\n", big_ptr);
	printf("printf orig: ");
	ret_printf = printf("Big ptr: %p\n", big_ptr);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste endereço 1
	ft_printf("--- Teste ponteiro 0x1 ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Ptr 0x1: %p\n", (void *)1);
	printf("printf orig: ");
	ret_printf = printf("Ptr 0x1: %p\n", (void *)1);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	/* ========== TESTES DE STRINGS ESPECIAIS ========== */

	// Teste string com só espaços
	ft_printf("--- Teste string só espaços ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("String: '%s'\n", "     ");
	printf("printf orig: ");
	ret_printf = printf("String: '%s'\n", "     ");
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste string muito longa
	ft_printf("--- Teste string longa ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("%s\n", "Esta é uma string muito muito muito muito muito muito muito muito longa para testar o comportamento");
	printf("printf orig: ");
	ret_printf = printf("%s\n", "Esta é uma string muito muito muito muito muito muito muito muito longa para testar o comportamento");
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste string com caracteres especiais
	ft_printf("--- Teste string com especiais ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("String: '%s'\n", "Hello\nWorld\tTest");
	printf("printf orig: ");
	ret_printf = printf("String: '%s'\n", "Hello\nWorld\tTest");
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	/* ========== TESTES DE ESPECIFICADORES SEGUIDOS ========== */

	// Teste especificadores sem espaços
	ft_printf("--- Teste especificadores colados ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("%d%d%d\n", 1, 2, 3);
	printf("printf orig: ");
	ret_printf = printf("%d%d%d\n", 1, 2, 3);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste só especificadores
	ft_printf("--- Teste só especificadores ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("%c%s%d%u%x", 'A', "B", 3, 4, 5);
	ft_printf("\n");
	printf("printf orig: ");
	ret_printf = printf("%c%s%d%u%x", 'A', "B", 3, 4, 5);
	printf("\nRetornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste múltiplos %%
	ft_printf("--- Teste múltiplos %% ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("%%%%%%%%%%\n");
	printf("printf orig: ");
	ret_printf = printf("%%%%%%%%%%\n");
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	/* ========== TESTES DE CASOS SEM CONVERSÃO ========== */

	// Teste sem conversão
	ft_printf("--- Teste sem conversão ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Texto simples sem conversao\n");
	printf("printf orig: ");
	ret_printf = printf("Texto simples sem conversao\n");
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste varios um %
	ft_printf("--- Teste %%%% ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("%%%%%%\n");
	printf("printf orig: ");
	ret_printf = printf("%%%%%%\n");
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	/* ========== TESTES MISTOS COMPLEXOS ========== */

	// Teste mix extremo
	ft_printf("--- Teste mix extremo ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("%c%s%p%d%i%u%x%X%%\n", 'Z', "test", NULL, INT_MIN, INT_MAX, UINT_MAX, 255, 255);
	printf("printf orig: ");
	ret_printf = printf("%c%s%p%d%i%u%x%X%%\n", 'Z', "test", NULL, INT_MIN, INT_MAX, UINT_MAX, 255, 255);
	printf("Retornos -> ft: %d | printf: %d\n\n", ret_ft, ret_printf);

	// Teste return sem conversão
	ft_printf("--- Teste return valores ---\n");
	ret_ft = ft_printf("123456789");
	printf("\nReturn sem conversão: %d (esperado: 9)\n", ret_ft);
	ret_ft = ft_printf("");
	printf("Return string vazia: %d (esperado: 0)\n\n", ret_ft);

	/* ========== TESTE DE % NO FINAL (UNDEFINED) ========== */

	// Teste % sozinho no final (comportamento indefinido)
	ft_printf("--- Teste %% no final (undefined) == -1 ---\n");
	ft_printf("meu printf:  ");
	ret_ft = ft_printf("Test%");
	printf("\nRetorno: %d (undefined behavior == -1)\n\n", ret_ft);

	ft_printf("=== FIM DOS TESTES ESPECIAIS ===\n");
	return (0);
}
