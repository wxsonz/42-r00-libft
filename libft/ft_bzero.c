/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:36:59 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:37:01 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// using memset because of the same mechanism
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// linear fill
/*
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = 0;
}
*/
// linear fill with loop unrolling
/*
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n >= 4)
	{
		*p++ = 0;
		*p++ = 0;
		*p++ = 0;
		*p++ = 0;
		n -= 4;

	}
	while (n--)
		*p++ = 0;
}
*/
