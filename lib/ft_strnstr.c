/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:18:42 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/01 13:34:45 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;

	len_little = ft_strlen(little);
	if (!len_little)
		return ((char *)big);
	while (*big && len > 0)
	{
		if (len_little <= len && !(ft_strncmp(big, little, len_little)))
			return ((char *)big);
		big++;
		len--;
	}
	return ((void *)0);
}
