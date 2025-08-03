/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:38:37 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:38:38 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// *L = [content = aa] [next = bb] 
// **L = [ [*L[0]=[aa],[-> bb]] 
//       , [*L[1]=[bb],[-> cc]] 
//       , [*L[2]=[cc],[-> NULL]] ]
// back = addr of *l[[cc],[-> NULL]]
// new = [void *] -> [NULL]
// if however *L just only made or having none child
// **L = [[void *] -> [NULL]]
// we can just assign its first element with *L[0] element with *new
// but if there are element inside, since we already got addr of the back
// back -> next = new
// *l[[cc],[-> NULL]] change -> NULL to -> *new

void	ft_lstadd_back(t_list **l, t_list *new)
{
	t_list	*back;

	if (*l == NULL)
	{
		*l = new;
		return ;
	}
	back = *l;
	while (back -> next)
		back = back -> next;
	back -> next = new;
}
