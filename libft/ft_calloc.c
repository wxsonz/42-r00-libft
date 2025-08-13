/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:37:21 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:37:22 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	*ft_calloc(size_t n, size_t size)
{
	void	*p;

	if (n && size > (size_t) -1 / n)
		return (0);
	n *= size;
	p = malloc(n);
	if (!p)
		return (p);
	ft_bzero(p, n);
	return (p);
}
*/

// size_t - 1 (excluded NULL)

/*
void	*ft_calloc(size_t n, size_t size)
{
	void	*new;

	if (n && size > (size_t) -1 / n)
		return (0);
	new = malloc(n * size);
	if (!new)
		return (NULL);
	ft_bzero(new, n * size);
	return (new);
}
*/


void	*ft_calloc(size_t n, size_t size)
{
	void	*new;

	if (n && size > 69420 / n)
		return (NULL);
	new = malloc(n * size);
	if (!new)
		return (NULL);
	ft_bzero(new, n * size);
	return (new);
}

/*
void  *ft_calloc(size_t n, size_t size)
{
  void  *new;

  new = malloc(n * size);
  if (!new)
    return (NULL);
  ft_bzero(new, n * size);
  return (new);
}
*/
