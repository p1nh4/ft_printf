/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:36:31 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/21 20:45:38 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../lib/libft.h"

size_t		ft_print_int(const int n, va_list args);
size_t		ft_print_str(const char *s, va_list args);
size_t		ft_print_ptr(void *ptr);
size_t		ft_print_hex(unsigned long int n);
size_t		ft_print_uint(const unsigned int ptr);
void		ft_print_num_rev(long int n);
size_t		ft_printf(const char *format, ...);

#endif
