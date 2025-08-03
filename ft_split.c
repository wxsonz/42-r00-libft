/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:44:20 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/14 00:02:20 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// loop the whole string
// if its a match with separator keep looking next addr until its not
// when its not if we are still in the string
// get current addr to wordstart
// set wordlen = 0
// while loop with if we are still in the string and its not separator
// and when the loop end it mean we are at the end of that word
// extract this word with ft_substring with data we have
// move *wordarr addr up to put in another word
// after we done NULL terminated the thing
/*
static char	**ft_free(char **str)
{
	while (str)
		free(*str--);
	free(str);
	return (NULL);
}
*/

static void	word_in(char **wordarr, const char *s, char c)
{
	const char	*wordstart;
	int			wordlen;

	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			wordstart = s;
			wordlen = 0;
			while (*s && *s != c)
			{
				wordlen++;
				s++;
			}
			*wordarr = ft_substr(wordstart, 0, wordlen);
			wordarr++;
		}
	}
	*wordarr = NULL;
}

// first loop to catch any char before word until its not anymore
// then we are in the word so if to increase the count for once
// after that exit the word with loop until we found another char
static int	word_count(const char *s, char c)
{
	int	wc;

	wc = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			wc++;
		while (*s && *s != c)
			s++;
	}
	return (wc);
}

char	**ft_split(const char *s, char c)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = word_count(s, c);
	new = malloc((size + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	word_in(new, s, c);
	return (new);
}
