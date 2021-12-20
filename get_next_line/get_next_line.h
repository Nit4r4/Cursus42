/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:06:30 by lgenevey          #+#    #+#             */
/*   Updated: 2021/12/20 16:10:18 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char    *get_next_line(int fd);
size_t  ft_strlen(const char *s, int ascii);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strdup(const char *s1);
char    *ft_substr(char *s, unsigned int start, size_t len);
char    *ft_free(char *str);

#endif
