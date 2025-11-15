/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:40:48 by davidos-          #+#    #+#             */
/*   Updated: 2025/10/18 21:44:05 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	if (!dest && !src)
		return ((void *)0);
	if (n == 0 && dest == src)
		return (dest);
	p_dest = (unsigned char *)dest;
	p_src = (const unsigned char *)src;
	if (p_src > p_dest)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (n--)
		{
			p_dest[n] = p_src[n];
		}
	}
	return (dest);
}
