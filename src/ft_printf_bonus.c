/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:52:28 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/13 19:52:55 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

size_t	ft_printf_bonus(const char *format, ...)
{
	size_t		t_len;
	va_list		args;
	t_flags		flags = {0};

	t_len = 0;
	//ft_bzero(&flags, sizeof(flags));
	va_start(args, format);
	if (format == ((void *)0) || *format == '\0' || ((*format == '%') && (*(format + 1) == '\0'))) //(format + 1) nao move o ptr, format++ sim
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			ft_parse_flags_bonus(&format, &flags);
			if (ft_strchr("cspdiuxX", (*format)))
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
/*	ft_printf_bonus("%5d", 42);     // imprime "   42" (3 espaços + 42)
	ft_printf_bonus("%5d", -5);     // imprime "   -5" (3 espaços + -5)
	ft_printf_bonus("%-5d", 42);    // imprime "42   " (42 + 3 espaços) - alinhado à esquerda
	ft_printf_bonus("%05d", 42);    // imprime "00042" (zeros à esquerda)
*/

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

	/*	t_flags flags = {0};
    const char *test = "10d";
    const char *ptr = test;

    ft_parse_flags_bonus(&ptr, &flags);
    printf("Width: %d\n", flags.width);      // deve dar 10
    printf("Remaining: %s\n", ptr);          // deve dar "d"
											 // */
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

	return 0;
}
