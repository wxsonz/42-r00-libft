/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:38:50 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 12:27:35 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// what we do is replace whatever in content with void * then let it free
// which is make it back to kind of original state 
// {
// 	void		*content;
// 	...
// }
// or
// **L = [[aa], [-> bb]] , [[bb], [-> cc]] ...
//
// del(*l[0]);
// **L = [[aa], [-> void *]] , [[void *], [-> cc]] ...
//
// use this in the middle of the list and it will cause to lost later list
void	ft_lstdelone(t_list *l, void (*del)(void *))
{
	if (l == NULL || del == NULL)
		return ;
	(*del)(l -> content);
	free(l);
}
