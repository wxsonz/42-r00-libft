/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:38:46 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 12:19:46 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// *lst -> next = *(lst -> next) next of **lst which doesnt exist 
// **lst just hold a pointer that point to *lst that hold [aa, -> bb]
// so we explicitly (*lst) to get the current *lst

void	ft_lstclear(t_list **l, void (*del)(void*))
{
	t_list	*tmp;

	if (l == NULL || del == NULL)
		return ;
	while (*l)
	{
		tmp = (*l)->next;
		del((*l)->content);
		free(*l);
		*l = tmp;
	}
	*l = NULL;
}
