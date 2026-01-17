
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:52:28 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/17 20:41:39 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:13:19 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/17 00:00:00 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_init_flags(t_flags *flags)
{
	flags->width = 0;
	flags->precision = -1;
	flags->plus = 0;
	flags->minus = 0;
	flags->zeros = 0;
	flags->space = 0;
	flags->hashtag = 0;
}

int	ft_printf(const char *format, ...)
{
	int		t_len;
	va_list	args;
	t_flags	flags;

	t_len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				break ;
			ft_init_flags(&flags);
			ft_parse_flags_bonus(&format, &flags);
			if (ft_strchr("cspdiuxX%", *format))
				t_len += ft_process_specifier_bonus(*format, args, &flags);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			t_len++;
		}
		format++;
	}
	va_end(args);
	return (t_len);
}


/*
#include "ft_printf_bonus.h"

size_t	ft_printf(const char *format, ...)
{
	size_t		t_len;
	va_list		args;
	t_flags		flags = {0, -1, 0, 0, 0, 0, 0};

	t_len = 0;
	//ft_bzero(&flags, sizeof(flags));
	va_start(args, format);
	if (format == ((void *)0) || *format == '\0' || ((*format == '%') && (*(format + 1) == '\0'))) //(format + 1) nao move o ptr, format++ sim
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			flags = (t_flags){0, -1, 0, 0, 0, 0, 0}; 
			ft_parse_flags_bonus(&format, &flags);
			if (ft_strchr("cspdiuxX%", (*format)))
				t_len += ft_process_specifier_bonus(*format, args, &flags);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			t_len++;
		}
		format++;
	}
	va_end(args);
	return (t_len);
}*/
/*
#include <stdio.h>
int main(void)
{
    int ret1, ret2;
    
    printf("=== TESTE 1: %%.7s ===\n");
    ret1 = ft_printf("[%.7s]\n", "hello world");
    ret2 = printf("[%.7s]\n", "hello world");
    printf("Teu: %d | Real: %d\n\n", ret1, ret2);
    
    printf("=== TESTE 2: %%.3s ===\n");
    ret1 = ft_printf("[%.3s]\n", "hello");
    ret2 = printf("[%.3s]\n", "hello");
    printf("Teu: %d | Real: %d\n\n", ret1, ret2);

    printf("=== TESTE 3: %%10.3s ===\n");
    ret1 = ft_printf("[%10.3s]\n", "hello");
    ret2 = printf("[%10.3s]\n", "hello");
    printf("Teu: %d | Real: %d\n\n", ret1, ret2);
    
    printf("=== TESTE 4: %%-10.5s ===\n");
    ret1 = ft_printf("[%-10.5s]\n", "hello world");
    ret2 = printf("[%-10.5s]\n", "hello world");
    printf("Teu: %d | Real: %d\n\n", ret1, ret2);
    
    return 0;
}
*/
/*
#include <stdio.h>

int main(void)
{
    ft_printf("Hello\n");
    ft_printf("[%-5c]", 'A');
    printf("\n");
    printf("[%-5c]", 'A');
    printf("\n");
    return 0;
}
*/
// test.c
/*
#include <stdio.h>

int main(void)
{
    printf("=== Teste básico ===\n");
    
    int ret1 = ft_printf("%-5c", 'A');
    printf(" | ret=%d\n", ret1);
    
    int ret2 = printf("%-5c", 'A');
    printf(" | ret=%d\n", ret2);
    
    return 0;
}
*/

/*
int main(void)
{
	// flags (+, space)
	ft_printf_bonus("Teste: %+d\n", 42); //+42
	ft_printf_bonus("Teste: % d\n", 42); // 42
	ft_printf_bonus("Teste: %d\n", -5);  //-5

	// flags (#)
	ft_printf_bonus("%x\n", 255);      //ff
	ft_printf_bonus("%#x\n", 255);     //0xff
	ft_printf_bonus("%X\n", 255);      //FF
	ft_printf_bonus("%#X\n", 255);     //0XFF
	ft_printf_bonus("%#x\n", 0);       //0x0

	// flags largura (%(x)d)
    ft_printf_bonus("%5d", 42);     // imprime "   42" (3 espaços + 42)
	ft_printf_bonus("%5d", -5);     // imprime "   -5" (3 espaços + -5)
	ft_printf_bonus("%-5d", 42);    // imprime "42   " (42 + 3 espaços) - alinhado à esquerda
	ft_printf_bonus("%05d", 42);    // imprime "00042" (zeros à esquerda)


	//largura (width), e com outras flags
	ft_printf_bonus("[%5d]\n", 42);
	ft_printf_bonus("[%5d]\n", -42);
	ft_printf_bonus("[%-5d]\n", 42);
	ft_printf_bonus("[%-5d]\n", -42);

	ft_printf_bonus("[% d]\n", -42);
	ft_printf_bonus("[% d]\n", 42);

	ft_printf_bonus("[%+ d]\n", 42);   // [+42]  e NÃO [ +42]
	ft_printf_bonus("[%+ d]\n", -42);  // [-42]

	ft_printf_bonus("[% 5d]\n", 42);  // [   42]
	ft_printf_bonus("[% 5d]\n", -42); // [  -42] e este esta [ -42]
	ft_printf_bonus("[% -5d]\n", 42);  // [ 42  ]
	ft_printf_bonus("[% -5d]\n", -42); // [-42  ] este esta [-42 ]
	ft_printf_bonus("[%+5d]\n", 42);    // [  +42]
	ft_printf_bonus("[%+5d]\n", -42);   // [  -42]

	ft_printf_bonus("[%5d]\n", 42);
	ft_printf_bonus("[%-5d]\n", 42);
	ft_printf_bonus("[%5d]\n", -42);
	ft_printf_bonus("[%+5d]\n", 42);
	ft_printf_bonus("[% 5d]\n", 42);

	t_flags flags = {0};
    const char *test = "10d";
    const char *ptr = test;

    ft_parse_flags_bonus(&ptr, &flags);
    printf("Width: %d\n", flags.width);      // deve dar 10
    printf("Remaining: %s\n", ptr);          // deve dar "d"
											 // 
	// char com largura
	ft_printf_bonus("[%5c]\n", 'A');
	ft_printf_bonus("[%-5c]\n", 'A');
	ft_printf_bonus("[%5c]\n", 'A');
	ft_printf_bonus("[%+5c]\n", 'A');
	ft_printf_bonus("[% 5c]\n", 'A');

	//uint com largura antes ou depois
    ft_printf_bonus("[%5u]\n", 0);
    ft_printf_bonus("[%-5u]\n", 0);
    ft_printf_bonus("[%5u]\n", 6);
    ft_printf_bonus("[%+5u]\n", -6);
    ft_printf_bonus("[%-3u]\n", 12);

	//string com largura antes e depois
	ft_printf_bonus("[%10s]\n", "oi");
    ft_printf_bonus("[%-10s]\n", "oie2");
    ft_printf_bonus("[%10s]\n", 0);
    ft_printf_bonus("[%-10s]\n", 0);

	//hex 0x e 0X com largura
    ft_printf_bonus("%10x\n", 255);
    ft_printf_bonus("%-10X\n", 255);
    ft_printf_bonus("%#10x\n", 255);
	ft_printf_bonus("%#10X\n", 255);
    ft_printf_bonus("%-#10x\n", 255);
    ft_printf_bonus("%#10x\n", 0);
    ft_printf_bonus("%-#10X\n", 0);
    ft_printf_bonus("%10x\n", 0);

	//ptr com largura antes ou depois
	int x = 42;
	ft_printf_bonus("[%20p]\n", &x);
	ft_printf_bonus("[%-20p]\n", &x);

	// diferentes formatos (d, i, u, x, X, p) com zeros na largura
	ft_printf_bonus("\n----Diferentes formatos (d, i, u, x, X, p) com zeros na largura----\n");
	ft_printf_bonus("[%05d]\n", 42);
   	ft_printf_bonus("[%+05d]\n", 42);
    ft_printf_bonus("[%05i]\n", 42);
  	ft_printf_bonus("[%05u]\n", 812);
    ft_printf_bonus("[%-05d]\n", 42);
	ft_printf_bonus("[%#06x]\n", 255);
	ft_printf_bonus("[%07x]\n", 255);
	ft_printf_bonus("[%#06X]\n", 255);
	ft_printf_bonus("[%#04x]\n", 0);
	ft_printf_bonus("[%04X]\n", 0);
	ft_printf_bonus("[%07X]\n", 255);
	ft_printf_bonus("[%05p]\n", 'A');

	//testando precisao
	ft_printf_bonus("[%.5d]\n", 42);
	ft_printf_bonus("[%+.5d]\n", 42);
	ft_printf_bonus("[%10.5d]\n", 42);// imprime "00042"
    ft_printf_bonus("[%9.3d]\n", -7);   // imprime "-007"
    ft_printf_bonus("[%-13.4d]\n", 42);
    ft_printf_bonus("[%+10.4d]\n", 42);

	// Teste 1: Flags básicos
	printf("\n=== TESTE 1: Flags básicos ===\n");
	ft_printf_bonus("%+d\n", 42);    // +42
	ft_printf_bonus("% d\n", 42);    // 42 (com espaço)
	ft_printf_bonus("%d\n", -42);    // -42

	// Teste 2: Largura
	printf("\n=== TESTE 2: Largura ===\n");
	ft_printf_bonus("[%10d]\n", 42);   // [        42]
	ft_printf_bonus("[%-10d]\n", 42);  // [42        ]
	ft_printf_bonus("[%10d]\n", -42);  // [       -42]

	// Teste 3: Flag 0
	printf("\n=== TESTE 3: Flag 0 ===\n");
	ft_printf_bonus("[%05d]\n", 42);    // [00042]
	ft_printf_bonus("[%+05d]\n", 42);   // [+0042]
	ft_printf_bonus("[%05d]\n", -42);   // [-0042]
	ft_printf_bonus("[%-05d]\n", 42);   // [42   ] (- ignora 0)

	// Teste 4: Precisão
	printf("\n=== TESTE 4: Precisão ===\n");
	ft_printf_bonus("[%.5d]\n", 42);      // [00042]
	ft_printf_bonus("[%+.5d]\n", 42);     // [+00042]
	ft_printf_bonus("[%.3d]\n", -7);      // [-007]
	ft_printf_bonus("[%10.5d]\n", 42);    // [     00042]

	// Teste 5: Flag 0 + Precisão (0 é ignorado)
	printf("\n=== TESTE 5: Flag 0 + Precisão ===\n");
	ft_printf_bonus("[%05.3d]\n", 42);    // [  042] (não 00042!)

	// Teste 6: Hex com #
	printf("\n=== TESTE 6: Hex ===\n");
	ft_printf_bonus("[%#x]\n", 255);      // [0xff]
	ft_printf_bonus("[%#10x]\n", 255);    // [     0xff]
	ft_printf_bonus("[%#010x]\n", 255);   // [0x000000ff]

	// Teste 7: Strings
	printf("\n=== TESTE 7: Strings ===\n");
	ft_printf_bonus("[%10s]\n", "oi");    // [        oi]
	ft_printf_bonus("[%-10s]\n", "oi");   // [oi        ]
	ft_printf_bonus("[%s]\n", NULL);      // [(null)]

	// Teste 8: Mix complexo
	printf("\n=== TESTE 8: Mix ===\n");
	ft_printf_bonus("[%+10.4d]\n", 42);   // [     +0042]
	ft_printf_bonus("[%-13.4d]\n", 42);   // [0042         ]


	//teste precision uint
	printf("\n=== TESTE: %%u com precisão ===\n");
	ft_printf_bonus("[%.5u]\n", 42);        // [00042]
	ft_printf_bonus("[%10.5u]\n", 42);      // [     00042]
	ft_printf_bonus("[%-10.5u]\n", 42);     // [00042     ]
	ft_printf_bonus("[%.3u]\n", 1);         // [001]
	ft_printf_bonus("[%.5u]\n", 0);         // [00000]
	ft_printf_bonus("[%8.5u]\n", 34);       // [   00034]

	//Teste precision hexadecimal
	printf("\n=== TESTE: %%x e %%X com precisão ===\n");
	ft_printf_bonus("[%.5x]\n", 255);      // [000ff]
	ft_printf_bonus("[%#.5x]\n", 255);     // [0x000ff]
	ft_printf_bonus("[%10.5x]\n", 255);    // [     000ff]
	ft_printf_bonus("[%.5X]\n", 255);      // [000FF]
	ft_printf_bonus("[%#.5X]\n", 255);     // [0X000FF]
	ft_printf_bonus("[%10.5X]\n", 255);    // [     000FF]


	//teste precisao str
	printf("\n=== TESTE: %%s com precisão ===\n");
	ft_printf_bonus("[%.5s]\n", "hello world");    // [hello]
	ft_printf_bonus("[%10.5s]\n", "hello");        // [     hello]
	ft_printf_bonus("[%.3s]\n", "oi");             // [oi]
	ft_printf_bonus("[%10.3s]\n", "hello");        // [       hel]
	ft_printf_bonus("[%-10.5s]\n", "hello");       // [hello     ]


	ft_printf_bonus("%-5c", 'A'); 
	return 0;
}
*/
