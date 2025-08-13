/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:39:31 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:39:32 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// WIP loop unrolling
void	*ft_memchr(const void *src, int c, size_t n)
{
	const unsigned char	*s;
	unsigned char		uc;

	s = src;
	uc = (unsigned char)c;
	while (n >= 4)
	{
		if (s[0] == uc || s[1] == uc || s[2] == uc || s[3] == uc)
			break ;
		s += 4;
		n -= 4;
	}
	while (n--)
	{
		if (*s == uc)
			return ((void *)s);
		s++;
	}
	return (0);
}
// checking char by char and counting with size of n
/*
void	*ft_memchr(const void *src, int c, size_t n)
{
	const unsigned char	*s;

	s = src;
	c = (unsigned char)c;
	while (n && *s != c)
	{
		s++;
		n--;
	}
	if (n)
		return ((void *)s);
	return (0);
}
*/
