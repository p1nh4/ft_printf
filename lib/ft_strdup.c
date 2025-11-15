/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:18:32 by davidos-          #+#    #+#             */
/*   Updated: 2025/10/24 23:15:37 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr_s;
	size_t	len_s;

	len_s = ft_strlen(s) + 1;
	ptr_s = malloc(len_s * sizeof(char));
	if (!ptr_s)
	{
		return ((void *)0);
	}
	ft_memcpy(ptr_s, s, len_s);
	return (ptr_s);
}
