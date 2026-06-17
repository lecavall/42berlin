/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecavall <lecavall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:41:30 by lecavall          #+#    #+#             */
/*   Updated: 2025/12/08 11:04:21 by lecavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
	{
		return (1);
	}
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%i", ft_isprint(' '));
// 	printf("%i", ft_isprint(126));
// 	printf("%i", ft_isprint(128));
// 	printf("%i", ft_isprint(255));
// 	return(0);
// }