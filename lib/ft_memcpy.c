/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:46:08 by davidos-          #+#    #+#             */
/*   Updated: 2025/10/18 21:46:22 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*s_dest;
	const unsigned char	*s_src;

	if (!src && !dest)
		return ((void *)0);
	if (n == 0 && dest == src)
		return (dest);
	s_dest = (unsigned char *)dest;
	s_src = (const unsigned char *)src;
	while (n > 0)
	{
		*s_dest++ = *s_src++;
		n--;
	}
	return (dest);
}
