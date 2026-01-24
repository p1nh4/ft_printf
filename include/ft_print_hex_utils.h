/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:27:27 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/24 19:04:41 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_HEX_UTILS_H
# define FT_PRINT_HEX_UTILS_H

# include "ft_printf_bonus.h"

typedef struct s_hex_params
{
	int	spaces;
	int	n_zeros;
	int	prefix;
}		t_hex_params;

int		ft_hex_len(unsigned long int n);
void	ft_print_padding(int count, char c);
void	ft_print_hex_num(unsigned long int n, char *base);
void	ft_print_prefix(int is_lower);

#endif
