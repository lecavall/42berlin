/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecavall <lecavall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:21:14 by lecavall          #+#    #+#             */
/*   Updated: 2026/03/05 11:12:31 by lecavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

//BE CAREFUL THAT THIS DOESN'T OVERWRITE THE COMPILATION DEFINITION
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// Main functions
char	*get_next_line(int fd);
char	*set_line(char *line);
char	*fill_line_buffer(int fd, char *left_c, char *buffer);

// Utility functions
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);

#endif