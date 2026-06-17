/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecavall <lecavall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:25:13 by lecavall          #+#    #+#             */
/*   Updated: 2025/12/01 14:47:28 by lecavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*setter;

	setter = (unsigned char *) b;
	while (len > 0)
	{
		*setter = (unsigned char) c;
		setter++;
		len--;
	}
	return (b);
}

/*
#include <string.h>
#include <stdio.h>
#include <stddef.h>

int	main(void)
{
	struct
	{
		int nbr;
		char a;
		char s[100];
	} b = {22, 'a', " hello world"};
	
	void *d = ft_memset(&b, '0', 4);
	printf("%d%c%s", b.nbr, b.a ,b.s);
	return (0);
}*/