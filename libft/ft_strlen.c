/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecavall <lecavall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:58:19 by lecavall          #+#    #+#             */
/*   Updated: 2025/12/05 18:18:55 by lecavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

/*
#include <string.h>
#include <stdio.h>
int	main(int argc, char** argv)
{
	int h = argc;
	h = 1;
	
	printf("String length is %lu\n", ft_strlen(argv[h]));
	printf("It actually is %lu", strlen(argv[1]));
	return(0);
}*/