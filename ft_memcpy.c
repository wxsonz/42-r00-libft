/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:43:24 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:43:25 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy 1 byte until remaining of both can divide by size of n 
// then copy with the size of n
// if there are still byte left copy them 1 byte size linearly
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				words;

	if (!dest && !src)
		return (dest);
	d = dest;
	s = src;
	while (n && ((size_t)d % sizeof(size_t) || (size_t)s % sizeof(size_t)))
	{
		*d++ = *s++;
		n--;
	}
	words = n / sizeof(size_t);
	while (words)
	{
		*(size_t *)d = *(size_t *)s;
		d += sizeof(size_t);
		s += sizeof(size_t);
		words--;
	}
	n %= sizeof(size_t);
	while (n--)
		*d++ = *s++;
	return (dest);
}

// linear copying with unsafe loop unrolling
/*
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	const unsigned char *s;

	if (!dest && !src)
		return (dest);
	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
*/
