/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecavall <lecavall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:rank2/test_ft_printf.c
/*   Created: 2025/12/23 12:14:59 by lecavallo         #+#    #+#             */
/*   Updated: 2026/01/09 14:23:16 by lecavallo        ###   ########.fr       */
=======
/*   Created: 2026/02/25 14:14:30 by lecavall          #+#    #+#             */
/*   Updated: 2026/03/05 10:39:20 by lecavall         ###   ########.fr       */
>>>>>>> 300d4069b0bfb20a6c47076e8ed964ea8baf6c25:projects/rank2/get_next_line/main_gnl_test.c
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

<<<<<<< HEAD:rank2/test_ft_printf.c



int main()
=======
int	main(int argc, char **argv)
>>>>>>> 300d4069b0bfb20a6c47076e8ed964ea8baf6c25:projects/rank2/get_next_line/main_gnl_test.c
{
	int		fd;
	int		i;
	char	*line;

<<<<<<< HEAD:rank2/test_ft_printf.c
    printf("Start the test, in this order: Edge cases, %%c %%s %%p %%d %%i %%u %%x %%X %%  \n\n");

    edgecases();
    printf("Test for %%c \n");
    printf("CV: %c \n", 'c');
    ft_pritf("MV: %c \n", 'c');



    return (1);
=======
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
>>>>>>> 300d4069b0bfb20a6c47076e8ed964ea8baf6c25:projects/rank2/get_next_line/main_gnl_test.c
}
