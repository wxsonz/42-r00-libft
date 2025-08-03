/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:39:13 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:39:13 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// barebone linked list 
t_list	*ft_lstnew(void *data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> content = data;
	new -> next = NULL;
	return (new);
}
