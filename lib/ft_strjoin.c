/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:12:04 by davidos-          #+#    #+#             */
/*   Updated: 2025/10/26 19:56:46 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat_s;
	size_t	len_s;

	len_s = ft_strlen(s1) + ft_strlen(s2) + 1;
	concat_s = malloc(len_s * sizeof(char));
	if (!concat_s)
		return ((void *)0);
	ft_strlcpy(concat_s, s1, len_s);
	ft_strlcat(concat_s, s2, len_s);
	return (concat_s);
}
