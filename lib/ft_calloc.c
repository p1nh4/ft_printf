/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:30:13 by davidos-          #+#    #+#             */
/*   Updated: 2025/10/22 23:55:40 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	t_memory;

	t_memory = nmemb * size;
	if (nmemb != 0 && (t_memory / nmemb) != size)
		return ((void *)0);
	ptr = malloc(t_memory);
	if (!ptr)
		return ((void *)0);
	else
		ft_bzero(ptr, t_memory);
	return (ptr);
}
