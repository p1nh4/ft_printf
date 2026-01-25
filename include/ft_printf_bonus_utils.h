/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:27:27 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/25 17:16:15 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_UTILS_H
# define FT_PRINTF_BONUS_UTILS_H

# include "ft_printf_bonus.h"

typedef struct s_print_params
{
	int	spaces;
	int	n_zeros;
	int	prefix;
}		t_print_params;

void		ft_print_padding(int count, char c);

// utils hex
int			ft_hex_len(unsigned long int n);
void		ft_print_hex_num(unsigned long int n, char *base);
void		ft_print_prefix(int is_lower);
// utils int
int			ft_get_num_len(long n);
void		ft_print_sign(int is_neg, t_flags *flags);
void		ft_putnbr_long(long n);
// utils uint
int			ft_get_uint_len(unsigned int n);
void		ft_putnbr_uint(unsigned int n);

#endif
