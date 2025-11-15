/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidos- <davidos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:21:16 by davidos-          #+#    #+#             */
/*   Updated: 2025/11/02 23:01:00 by davidos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len_s;
	char	*p_s;
	char	*start_ps;

	if (!s || !f)
		return ((void *)0);
	len_s = ft_strlen(s);
	p_s = malloc((len_s + 1) * sizeof(char));
	if (!p_s)
		return ((void *)0);
	i = 0;
	start_ps = p_s;
	while (*s)
	{
		*p_s++ = f(i++, *s);
		s++;
	}
	*p_s = '\0';
	return (start_ps);
}
