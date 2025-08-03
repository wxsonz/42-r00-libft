/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:45:05 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:45:06 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t n)
{
	const char	*p;

	p = ft_memchr(s, 0, n);
	if (p)
		return (p - s);
	return (n);
}

size_t	ft_strlcat(char *d, const char *s, size_t n)
{
	size_t	l;

	l = ft_strnlen(d, n);
	if (l == n)
		return (l + ft_strlen(s));
	return (l + ft_strlcpy (d + l, s, n - l));
}
