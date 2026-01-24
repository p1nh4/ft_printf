/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:17:08 by davidos-          #+#    #+#             */
/*   Updated: 2026/01/24 17:32:17 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_hex_utils.h"

int      ft_hex_len(unsigned long int n)
{
        int     len;

        len = 0;
        if (n == 0)
                return (1);
        while (n > 0)
        {
                n /= 16;
                len++;
        }
        return (len);
}

void     ft_print_padding(int count, char c)
{
        while (count-- > 0)
                ft_putchar_fd(c, 1);
}

void	ft_print_hex_num(unsigned long int n, char *base)
{
        if (n >= 16)
                ft_print_hex_num(n / 16, base);
        ft_putchar_fd(base[n % 16], 1);
}

void     ft_print_prefix(int is_lower)
{
        ft_putchar_fd('0', 1);
        if (is_lower)
                ft_putchar_fd('x', 1);
        else
                ft_putchar_fd('X', 1);
}
