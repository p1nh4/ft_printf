/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:13:19 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/07 21:35:22 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../lib/libft.h"

//# define bool int
//# define true 1
//# define false 0

typedef struct  s_flags
{
        int             width;
        int             precision;
        char    plus;
        char    minus;
        char    zeros;
        char    space;
        char    hashtag;

}                               t_flags;


size_t  ft_print_char(int c);
size_t  ft_print_str(char *s);
size_t  ft_print_ptr(void *ptr);
size_t  ft_print_int(int n);
size_t  ft_print_num_rev(long int n);
size_t  ft_print_uint(unsigned int ptr);
size_t  ft_print_hex(unsigned long int n, int is_lower);
size_t  ft_print_percent(char c);
size_t  ft_process_specifier(char format, va_list args);
void	ft_parse_flags_bonus(const char **format, t_flags *flags);
size_t  ft_printf(const char *format, ...);

#endif
