/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:36:52 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:36:55 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
int	mini_isspace(int c)
{
	return c == ' ' || (unsigned)c - '\t' < 5;
}

int	mini_isdigit(int c)
{
	return (unsigned)c - '0' < 10;
}

int	mini_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	mini_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
*/

int	ft_atoi(const char *s)
{
	int	n;
	int	neg;

	n = 0;
	neg = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
		neg = ',' - *s++;
	while (*s >= '0' && *s <= '9')
		n = 10 * n + (*s++ - '0');
	return (n * neg);
}
