/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecavall <lecavall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:47:57 by lecavall          #+#    #+#             */
/*   Updated: 2025/12/01 13:01:45 by lecavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i", ft_isalpha('a'));
	printf("%i", ft_isalpha('z'));
	printf("%i", ft_isalpha('A'));
	printf("%i", ft_isalpha('Z'));
	printf("%i", ft_isalpha('1'));
	return(0);
}*/