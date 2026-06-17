/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecavall <lecavall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:31:41 by lecavall          #+#    #+#             */
/*   Updated: 2025/12/01 13:01:49 by lecavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
	{
		return (1);
	}
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%i", ft_isascii('0'));
	printf("%i", ft_isascii('h'));
	printf("%i", ft_isascii('i'));
	printf("%i", ft_isascii(345345345345345345));
	return(0);
}*/