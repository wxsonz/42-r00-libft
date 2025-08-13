/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:38:33 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:38:33 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// helper function to count len of int
// if we have to use this in any case len will always be atleast 1
static int	ft_intlen(int n)
{
	int		len;
	long	num;

	len = 1;
	num = n;
	if (n < 0)
	{
		len++;
		num = -num;
	}
	while (num >= 10)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*buffer;
	int		size;
	long	num;

	size = ft_intlen(n);
	buffer = malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (NULL);
	buffer[size] = '\0';
	buffer[0] = '0';
	if (n == 0)
		return (buffer);
	num = n;
	if (n < 0)
	{
		buffer[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		buffer[--size] = (num % 10) + '0';
		num /= 10;
	}
	return (buffer);
}
