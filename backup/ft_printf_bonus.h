/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:13:19 by davidos-          #+#    #+#             */
/*   Updated: 2025/12/19 14:34:56 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include "../lib/libft.h"

# define LOWER_CASE 1
# define UPPER_CASE 0

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

size_t  ft_print_char_bonus(int c, t_flags *flags);
size_t  ft_print_str_bonus(char *s, t_flags *flags);
size_t  ft_print_ptr_bonus(void *ptr, t_flags *flags);
size_t  ft_print_int_bonus(int n, t_flags *flags);
//size_t  ft_print_num_rev(long int n);
//int		ft_len_uint(unsigned int n);
size_t  ft_print_uint_bonus(unsigned int n, t_flags *flags);
size_t  ft_print_hex_bonus(unsigned long int n, int is_lower, t_flags *flags);
size_t  ft_print_percent_bonus(char c, t_flags *flags);
size_t  ft_process_specifier_bonus(char format, va_list args, t_flags *flags);
void	ft_parse_flags_bonus(const char **format, t_flags *flags);
size_t  ft_printf(const char *format, ...);

#endif 
