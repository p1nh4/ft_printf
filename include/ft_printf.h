/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:36:31 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/23 15:43:52 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../lib/libft.h"

size_t		ft_print_int(const int n, va_list args);
size_t		ft_print_str(const char *s, va_list args);
size_t		ft_print_ptr(void *ptr);
size_t		ft_print_hex(unsigned long int n, int flag);
size_t		ft_print_uint(const unsigned int ptr);
void		ft_print_num_rev(long int n);
size_t		ft_print_percent(char c);
size_t		ft_printf(const char *format, ...);

#endif
