/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:52:28 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/05 21:53:29 by davidos-         ###   ########.fr       */
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

	return 0;
}
