/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecavall <lecavall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:19:10 by lecavall          #+#    #+#             */
/*   Updated: 2025/12/05 18:14:32 by lecavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

static int	isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}

int	ft_isalnum(int c)
{
	if (isalpha(c) || isdigit(c))
	{
		return (1);
	}
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%i", ft_isalnum('0'));
	printf("%i", ft_isalnum('h'));
	printf("%i", ft_isalnum('i'));
	printf("%i", ft_isalnum('*'));
	return(0);
}*/