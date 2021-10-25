/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:25:09 by lgenevey          #+#    #+#             */
/*   Updated: 2021/10/25 15:30:26 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stddef.h>

int		ft_isalpha(int c);
int		ft_isdigit(int d);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
long	ft_strlen(const char *s);
void	*ft_memset(void *pointer, int value, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t	ft_strlcat(char *dest, const char *src, size_t destsize);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

#endif
