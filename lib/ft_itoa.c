/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:27:38 by davidos-          #+#    #+#             */
/*   Updated: 2025/10/29 22:11:08 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len(int n);

char	*ft_itoa(int n)
{
	char		*s;
	size_t		len_n;
	long int	l_n;

	l_n = n;
	len_n = ft_len(n);
	s = malloc((len_n + 1) * sizeof(char));
	if (!s)
		return ((void *)0);
	if (l_n == 0)
		s[l_n] = '0';
	if (l_n < 0)
	{
		s[0] = '-';
		l_n *= -1;
	}
	s[len_n] = '\0';
	while (l_n)
	{
		s[--len_n] = (l_n % 10) + '0';
		l_n /= 10;
	}
	return (s);
}

size_t	ft_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
