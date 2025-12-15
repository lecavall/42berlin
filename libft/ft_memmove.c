/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecavall <lecavall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:18:23 by lecavall          #+#    #+#             */
/*   Updated: 2025/12/05 18:15:13 by lecavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*giver;
	unsigned char	*receiver;

	receiver = (unsigned char *) dest;
	giver = (unsigned char *) src;
	if (!src && !dest)
		return (NULL);
	if (dest > src)
	{
		while (0 < n--)
		{
			receiver[n] = giver[n];
		}
	}
	else
	{
		while (n-- > 0)
		{
			*(receiver++) = *(giver++);
		}
	}
	return (dest);
}

/*
#include <string.h>
#include <stdio.h>
#include <stddef.h>

int	main(void)
{
	struct hello
	{
		char s[13];
		char a;
	} b = {" hello world", 'a'};
	
	
	struct hello d;
	struct hello e;
	
	ft_memmove(&d, &b, sizeof(b));
	memmove (&e, &b, sizeof(b));
	
	printf("%c%s\n", d.a ,d.s);
	printf("%c%s", e.a ,e.s);
	return (0);
}
*/