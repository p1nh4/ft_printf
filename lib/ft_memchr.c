/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:05:36 by davidos-          #+#    #+#             */
/*   Updated: 2025/10/21 23:19:14 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr_s;

	ptr_s = (unsigned char *)s;
	while (n--)
	{
		if (*ptr_s++ == (unsigned char )c)
			return ((char *)(ptr_s - 1));
	}
	return ((void *)0);
}
