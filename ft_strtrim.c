/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:46:07 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:46:08 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// loop forward and backward to check which part need extract
// throw this in ft_substr to extract out the part we want
char	*ft_strtrim(const char *str, const char *set)
{
	char	*new;
	size_t	start;
	size_t	end;

	if (!str)
		return (NULL);
	if (!set)
		return (ft_strdup(str));
	start = 0;
	end = ft_strlen(str) - 1;
	while (str[start] && ft_strchr(set, str[start]))
		start++;
	while (str[end] && ft_strchr(set, str[end]))
		end--;
	new = ft_substr(str, start, end - start + 1);
	return (new);
}
