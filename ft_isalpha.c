/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:37:33 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:37:34 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// bit shift 32 = 00 10 00 00
// A = 01 00 00 01
// a = 01 10 00 01
// B = 01 00 00 10
// b = 01 10 00 01
// C = 01 00 00 11
// c = 01 10 00 11
// the only difference between lower and upper is 00 X0 00 00
// we can add/remove 1 to X or 6th bit then compare to lower/upper
// | OR bitwise for compare to lowercase
// & AND bitwise for compare to uppercase

// example we put A in
// A = 01 00 00 01 
// 32= 00 10 00 00
//     01 10 00 01 = a

// example with z
// z = 01 11 10 10 
// 32= 00 10 00 00
//     01 11 10 10 = z
// z - a < 26
// 122 - 97 = 25
int	ft_isalpha(int c)
{
	return (((unsigned)c | 32) - 'a' < 26);
}
// uppercase impractical
/*
int	ft_isalpha(int c)
{
	return ((unsigned)c & ~32) - 'A' < 26;
}
*/
