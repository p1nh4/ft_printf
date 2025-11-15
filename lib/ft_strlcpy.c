/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:21:34 by davidos-          #+#    #+#             */
/*   Updated: 2025/10/19 10:41:13 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	s_len;

	s_len = ft_strlen(src);
	if (s_len >= size)
		len = size - 1;
	else
		len = s_len;
	if (size)
	{
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (s_len);
}
