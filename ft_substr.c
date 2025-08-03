/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:46:11 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 12:18:57 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// extract substring from start of n size
// locate where to extract
// if n size we want to extract are exceeding the size of str + start
// make it the same with size so we dont going over '\0'
// using strlcpy to copy to new substring
char	*ft_substr(const char *s, unsigned int start, size_t n)
{
	char	*sub;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (n > size)
		n = size;
	sub = malloc((n + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, n + 1);
	return (sub);
}
