/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:36:23 by davidos-          #+#    #+#             */
/*   Updated: 2025/10/26 17:43:27 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr_s;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (start >= len_s)
		len = 0;
	else if (len > (len_s - start))
		len = (len_s - start);
	ptr_s = malloc((len + 1) * sizeof(char));
	if (!ptr_s)
		return ((void *)0);
	if (start < len_s)
		s += start;
	ft_strlcpy(ptr_s, s, (len + 1));
	return (ptr_s);
}
