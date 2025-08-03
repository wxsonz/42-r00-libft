/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:45:59 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:46:00 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// simple implementation
// bottleneck by ft_strlen && strncmp
char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	size_t		flen;

	if (!*find)
		return ((char *)s);
	flen = ft_strlen(find);
	if (!slen)
		return (NULL);
	while (*s && flen <= slen)
	{
		if (*s == *find && ft_strncmp(s, find, flen) == 0)
			return ((char *)s);
		s++;
		slen--;
	}
	return (NULL);
}
