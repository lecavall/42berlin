/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecavall <lecavall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:14:30 by lecavall          #+#    #+#             */
/*   Updated: 2026/03/05 10:39:20 by lecavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	if (argc < 2)
		return (1);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "ERROR", 6), 0);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		i++;
		free (line);
	}
	return (0);
}
