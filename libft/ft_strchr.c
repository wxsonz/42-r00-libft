/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:44:25 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:44:26 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	*ft_strchr(const char *s, int c)
{
	c = (unsigned char)c;
	if (!c)
		return (char *)s;
	while (*s && *(unsigned char *)s != c)
		s++;
	if (*(unsigned char *)s == c)
		return (char *)s;
	return (NULL);
}
*/

/*
add this as first instruction to avoid segfault
	if (s == NULL)
		return (NULL);
*/
char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	char			*sp;

	uc = (unsigned char)c;
	sp = (char *)s;
	while (*sp)
	{
		if (*sp == uc)
			return (sp);
		sp++;
	}
	if (!uc)
		return (sp);
	return (NULL);
}
