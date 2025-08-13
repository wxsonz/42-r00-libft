/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:45:56 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:45:57 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// musl based
// checking up to count if string1 and string2 are equal or not

// if (!n--)
// to handle

// while condition
// l and r is not out of bound
// and not out of n
// and char or l and r still the same
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*l;
	const unsigned char	*r;

	l = (void *)s1;
	r = (void *)s2;
	if (!n--)
		return (0);
	while (*l && *r && n && *l == *r)
	{
		l++;
		r++;
		n--;
	}
	return (*l - *r);
}
