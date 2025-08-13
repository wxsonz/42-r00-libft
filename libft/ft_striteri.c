/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:44:33 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:44:47 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// no mutate 100%
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	char			*sp;

	if (!s || !f)
		return ;
	i = 0;
	sp = s;
	while (*sp)
	{
		f(i, sp);
		i++;
		sp++;
	}
}
