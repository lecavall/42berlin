/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecavall <lecavall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:57:04 by lecavall          #+#    #+#             */
/*   Updated: 2025/12/01 17:13:25 by lecavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*receiver;
	unsigned char	*giver;

	if (dest == (void *)0 && src == (void *)0)
	{
		return (dest);
	}
	receiver = (unsigned char *) dest;
	giver = (unsigned char *) src;
	while (n > 0)
	{
		*(receiver++) = *(giver++);
		n--;
	}
	return (dest);
}

// The memcpy function copies maximum n bytes from src to dst.
//  The man talks about memory overlapping, I'll explain this 
//  with details on the memmove function page.

// As for memset and bzero we'll need some temporary pointers 
// to manipulate our data.

// This functions works like the strcpy function, except that 
// memcpy accepts void * as parameters, so we can give it any 
// type of pointer we want to copy.

/*
#include <string.h>
#include <stdio.h>
#include <stddef.h>

int	main(void)
{
	struct hello
	{
		char s[13];
		int nbr;
		char a;
	} b = {" hello world", 485357, 'a'};
	
	struct hello d;
	
	ft_memcpy(&d, &b, sizeof(b));
	printf("%d%c%s", d.nbr, d.a ,d.s);
	return (0);
}*/