/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchaipro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:45:14 by wchaipro          #+#    #+#             */
/*   Updated: 2024/09/10 11:45:39 by wchaipro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* experimenting bsd implementation
*/

//#include <unistd.h>
//#include <fcntl.h>
//#include <time.h>
//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdint.h>
//#include <limits.h>

//static inline size_t	ft_sptr(const char *p, const char *s, int x)
//{
//	if (p[x] == '\0')
//		return (p - s + x);
//	return (size_t)(-1);
//}
//
//size_t	ft_strlen3(const char *s)
//{
//	const char		*p;
//	const unsigned long	*lp;
//	unsigned long			va;
//	unsigned long			vb;
//	size_t			res;
//
//	lp = (const unsigned long *)((uintptr_t)s & ~(sizeof(long) - 1));
//	va = (*lp - 0x01010101);
//	vb = ((~*lp) & 0x80808080);
//	//va = (*lp - 0x0101010101010101);
//	//vb = ((~*lp) & 0x8080808080808080);
//	lp++;
//	if (va & vb)
//	{
//		p = s;
//		while (p < (const char *)lp)
//		{
//			if (*p == '\0')
//				return (p - s);
//			p++;
//		}
//	}
//	while (lp++)
//	{
//		va = (*lp - 0x01010101);
//		vb = ((~*lp) & 0x80808080);
//		//va = (*lp - 0x0101010101010101);
//		//vb = ((~*lp) & 0x8080808080808080);
//		//printf("va = %ld, vb = %ld\n", va, vb);
//		if (va & vb)
//		{
//			p = (const char *)(lp);
//			if ((res = ft_sptr(p, s, 0)) != (size_t)(-1)) return res;	
//			if ((res = ft_sptr(p, s, 1)) != (size_t)(-1)) return res;	
//			if ((res = ft_sptr(p, s, 2)) != (size_t)(-1)) return res;	
//			if ((res = ft_sptr(p, s, 3)) != (size_t)(-1)) return res;	
//			//if ((res = ft_sptr(p, s, 4)) != (size_t)(-1)) return res;	
//			//if ((res = ft_sptr(p, s, 5)) != (size_t)(-1)) return res;	
//			//if ((res = ft_sptr(p, s, 6)) != (size_t)(-1)) return res;	
//			//if ((res = ft_sptr(p, s, 7)) != (size_t)(-1)) return res;	
//		}
//		//write(1, "Test\n", 5);
//	}
//	return (res);
//}

// musl implementation

//size_t	ft_strlen(const char *s)
//{
//	const char	*a;
//
//	a = s;
//	while (*s)
//		s++;
//	return (s - a);
//}

// i yoinked and simplified from glibc, musl and freebsd
// the optimization here is to help with misalignment
// theoretically 3-6 times faster than string++ until NULL is found
// in memory(cache line) when running ft_strlen on x86
// where x86 would support unalign loads and stores
//
// https://www.kernel.org/doc/Documentation/unaligned-memory-access.txt
//
// now the problem but visualize in my style
//
// asumming this is your memory in simplest version
//
// [0x1000] ?? ?? ?? ?? ?? ?? h_ e_
// [0x1008] l_ l_ o_ 32 w_ o_ r_ l//_
// [0x1010] d_ \0 ?? ?? ?? ?? ?? ??
//
// cpu will fetch the data in cache line 64bytes
// while the cpu word size will depends on how many bits it is
// check with `getconf LONG_BIT`
//
// (cache line or block is the smallest unit of data
// that can be transferred between the cache and main memory)
//
// when you normally load data in x86 misaligned
//
// > fetch in 64 bytes from cache line
// [0x1000] ?? ?? ?? ?? ?? ?? h_ e_
// [0x1008] l_ l_ o_ 32 w_ o_ r_ l_
// [0x1010] d_ \0 ?? ?? ?? ?? ?? ??
// ...
// [0x103F] ?? ?? ?? ?? ?? ?? ?? ??
//
// > and then we do strlen as normal from byte to byte
// (because we throw in *string
// it gonna start at 0x1006 in this example)
//
// [0x1006] h		len++
// [0x1007] e		len++
// ------------------------------
// [0x1008] l		len++
// [0x1009] l		len++
// [0x100A] o		len++
// [0x100B] SPACE	len++
// [0x100C] w		len++
// [0x100D] o		len++
// [0x100E] r		len++
// [0x100F] l		len++
// ------------------------------
// [0x1010] d		len++
// [0x1011] \0
// [0x1012] ??
// [0x1013] ??
// ...
// > and then we return len
//
// but in this optimized version
// uintptr_t of string will split out the addr
// sizeof(unsigned long) to split out the word size
// which is 8 on 64bit and 4 on 32bit
//
// [0x1006] h		0x1006 % 8 = 0 ? nope its 6
// is the current pointer a null? nope
// lets move *string up
// [0x1007] e		0x1007 % 8 = 0 ? nope its 7
// is the current pointer a null? nope
// lets move *string up
// [0x1008] l		0x1008 % 8 = 0 ? yes
// alright now we mark current addr with *w
//
// then magic number time
// use the magic number that will locate a null and break the loop
// else we just keep moving up by ulong size or LONG_BIT
//
// now that we move up by 8
// we are now at 
// [0x1010] d
// and when we do the magic number again 
// the result will have atleast 1 0x80
// (because in this 8 bytes we have \0 on 0x1011)
// which is > 0 which will break
//
// then we keep moving the pointer until NULL linearly
//
// and at the end we will
// substract \0 addr with start addr
// which will give the length from start of original string to null
size_t	ft_strlen(const char *s) 
{
	const unsigned long	*w;
	const char		*start;
	unsigned long		val;

	start = s;
	//while ((uintptr_t)s % sizeof(unsigned long))
	while((uintptr_t)s % 8)
	{
		if (!*s) 
			return s - start;
		s++;
	}
	w = (const unsigned long *)s;
	while (1) 
	{
		val = *w;
		if (val - (~0UL / 255) & ~val & ((~0UL / 255) * 128))
			break ;
		w++;
	}
	s = (const char *)w;
	while (*s)
		s++;
	return (s - start);
}


//int	main(void)
//{
//	char	buffer[1000000];
//	float	seconds;
//	size_t	len;
//	clock_t	start;
//	clock_t	end;
//
//
//	int fd = open("./tmp", O_RDONLY); 
//	printf("%d\n", read(fd, buffer, 1000000));
//
//	start = clock();
//	len = ft_strlen(buffer);
//	end = clock();
//	seconds = (float)(end - start) / CLOCKS_PER_SEC;
//	printf("ft_strlen           = %.10f, count = %d\n", seconds, len);
//
//	//start = clock();
//	//len = ft_strlen2(buffer);
//	//end = clock();
//	//seconds = (float)(end - start) / CLOCKS_PER_SEC;
//	//printf("ft_2 = %.10f, count = %d\n", seconds, len);
//
//	//start = clock();
//	//len = ft_strlen3(buffer);
//	//end = clock();
//	//seconds = (float)(end - start) / CLOCKS_PER_SEC;
//	//printf("ft_3 = %.10f, count = %d\n", seconds, len);
//
//	start = clock();
//	len = ft_strlen4(buffer);
//	end = clock();
//	seconds = (float)(end - start) / CLOCKS_PER_SEC;
//	printf("ft_strlen_optimized = %.10f, count = %d\n", seconds, len);
//
//	start = clock();
//	len = strlen(buffer);
//	end = clock();
//	seconds = (float)(end - start) / CLOCKS_PER_SEC;
//	printf("original_strlen     = %.10f, count = %d\n", seconds, len);
//
//	//write(1, buffer, 100000);
//	return (0);
//}
