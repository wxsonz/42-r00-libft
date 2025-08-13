/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:46:02 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:46:04 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static char	*ft_memrchr(const char *s, int c)
{
	const unsigned char	*s;
	
	s = m;
	c = (unsigned char)c;
	while (n--)
		if (s[n] == c)
			return (void *)(s + n);
	return (0);
}
*/

// set sp to the end
// compare both addr then check backward
char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	char			*sp;

	uc = (unsigned char)c;
	sp = (char *)s;
	while (*sp)
		sp++;
	while (sp >= s)
	{
		if (*sp == uc)
			return (sp);
		sp--;
	}
	if (!uc)
		return ((char *)(sp + 1));
	return (NULL);
}
