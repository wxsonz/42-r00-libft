/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:44:00 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:44:00 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* simple byte linear fill
void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char *s;

	s = dest;
	while (n--)
		*s++ = c;
	return (dest);
}
*/

// read ft_strlen about unalignment issue

// c (-2147483648 ~ 2147483647)
// but in this case its most likely ascii (0 ~ 255) 
// (unsigned char)c (0 ~ 255)
// unsigned char to ensure of 0 ~ 255
// (unsigned long)(unsigned char)c
// assuming the character is B
// the bit will be 0x42
// convert the bit from 0x42 to unsigned long
// it become 0x00000042 (32bit) or 0x0000000000000042 (64bit)
// ~0UL (~ not, 0UL = 0 bit of unsigned long (0x000..))
// ~0UL == ULONG_MAX but without the need of limits.h
// ~0UL = 0xFFFFFFFF, 0xFFFFFFFFFFFFFFFF
// (~0UL / 255) = 0x01010101, 0x0101010101010101
// so when we multiply 
// 0x42 * 0x01010101 = 0x42424242
// we skip the need of filling 0x42 4 or 8 times linearly

// if n still remain, loop fill byte until end

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*dst;
	unsigned long	*dst_cccc;
	unsigned long	cccc;

	dst = dest;
	while (n && ((unsigned long)dst & (sizeof(unsigned long) - 1)))
	{
		*dst++ = (unsigned char)c;
		n--;
	}
	if (n >= sizeof(unsigned long))
	{
		cccc = (unsigned long)(unsigned char)c * (~0UL / 255);
		dst_cccc = (unsigned long *)dst;
		while (n >= sizeof(unsigned long))
		{
			*dst_cccc++ = cccc;
			n -= sizeof(unsigned long);
		}
		dst = (unsigned char *)dst_cccc;
	}
	while (n--)
		*dst++ = (unsigned char)c;
	return (dest);
}
