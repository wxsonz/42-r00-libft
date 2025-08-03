/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:44:55 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:45:02 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	
	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, ft_strlen(s1) + 1);
	ft_strlcat(dst, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (dst);
}
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	l1;
	size_t	l2;
	size_t	l3;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	l3 = l1 + l2;
	dst = malloc(sizeof(char) * l3 + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, l1 + 1);
	ft_strlcat(dst, s2, l3 + 1);
	return (dst);
}
