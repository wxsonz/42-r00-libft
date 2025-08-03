/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:45:43 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:45:51 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// striteri but spawn fresh one out
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;
	size_t			slen;

	if (!s || !f)
		return (NULL);
	slen = ft_strlen(s);
	s2 = malloc(sizeof(char) * (slen + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (*s)
	{
		s2[i] = f(i, *s);
		i++;
		s++;
	}
	s2[i] = '\0';
	return (s2);
}
