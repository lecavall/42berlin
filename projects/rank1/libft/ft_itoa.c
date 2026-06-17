/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecavall <lecavall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:34:35 by lecavall          #+#    #+#             */
/*   Updated: 2025/12/08 13:17:06 by lecavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long nbr);

char	*ft_itoa(int n)
{
	char	*res;
	long	nbr;
	int		len;
	int		i;
	int		pos;

	nbr = n;
	len = int_len(nbr);
	res = (char *) ft_calloc(sizeof(char), len + 1);
	if (!res)
		return (NULL);
	pos = len;
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
		pos--;
	}
	i = -1;
	while (++i < pos)
	{
		res[len - 1 - i] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (res);
}

static int	int_len(long nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	if (nbr == 0)
		len = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	test = -0;
// 	printf("%s", ft_itoa(test));
// 	return (0);
// }