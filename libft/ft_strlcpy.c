/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:45:09 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:45:10 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char	*d0;
	size_t	*wd;
	
	return (strlen
}
*/

// bottleneck by strlen
/*
size_t	ft_strlcpy(char *d, const char *s, size_t n)
{
	char	*d0;

	d0 = d;
	if (!n)
		return (ft_strlen(s));
	while (--n)
	{
		*d = *s;
		if (*s == '\0')
			break ;
		d++;
		s++;
	}
	*d = '\0';
	return (d - d0 + ft_strlen(s));
}
*/

size_t	ft_strlcpy(char *d, const char *s, size_t dsize)
{
	size_t	slen;

	slen = ft_strlen(s);
	if (slen + 1 < dsize)
		ft_memcpy(d, s, slen + 1);
	else if (dsize != 0)
	{
		ft_memcpy(d, s, dsize - 1);
		d[dsize - 1] = 0;
	}
	return (slen);
}
