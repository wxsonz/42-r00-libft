/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:38:41 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:38:42 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// L1 = BIGLIST[...]
// L2 = [zz]
// set next addr of L2 to be addr of *L1
// BIGLIST[ -> [aa] -> [bb] -> [cc] -> [NULL]]
//              ^^
//             [zz]     
// then we can safely replace the original addr of *L1 with L2
void	ft_lstadd_front(t_list **l1, t_list *l2)
{
	l2 -> next = *l1;
	*l1 = l2;
}
