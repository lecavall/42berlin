/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecavall <lecavall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:03:00 by lecavall          #+#    #+#             */
/*   Updated: 2025/12/01 14:47:42 by lecavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*setter;

	setter = (unsigned char *) s;
	while (n > 0)
	{
		*setter = 0;
		setter++;
		n--;
	}
}

/*
#include <string.h>
#include <stdio.h>
#include <stddef.h>

int	main(void)
{
	struct
	{
		char s[13];
		int nbr;
		char a;
	} b = {" hello world", 22, 'a'};
	
	ft_bzero(&b, 4);
	printf("%d%c%s", b.nbr, b.a ,b.s);
	return (0);
}*/