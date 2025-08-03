/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:44:29 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:44:30 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// freebsd style: quick to avoid nothing in str
// wip
/*
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;
	
	copy = NULL;
	if (s)
	{
		len = ft_strlen(s) + 1;
		if ((copy = malloc(len)) == NULL)		
			return (NULL);
		ft_memcpy(copy, s, len);
	}
	return (copy);
}
*/

// musl style simple and short
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*d;

	len = ft_strlen(s);
	d = malloc(len + 1);
	if (!d)
		return (NULL);
	return (ft_memcpy(d, s, len + 1));
}
