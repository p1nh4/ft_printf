/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 21:31:24 by davidos-          #+#    #+#             */
/*   Updated: 2025/10/26 22:56:04 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_contains_char(char const *set, char c);

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trim_s1;
	const char	*start;
	const char	*end;
	size_t		len;

	start = s1;
	while (start && ft_contains_char(set, *start))
		start++;
	end = s1 + (ft_strlen(s1) - 1);
	while (end > start && ft_contains_char(set, *end))
		end--;
	len = (end - start) + 1;
	trim_s1 = ft_substr(s1, start - s1, len);
	return (trim_s1);
}

int	ft_contains_char(char const *set, char c)
{
	if (ft_memchr(set, c, ft_strlen(set)))
		return (1);
	return (0);
}
