/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:38:30 by lgenevey          #+#    #+#             */
/*   Updated: 2021/12/20 16:21:55 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * retourne la taille d'une chaine jusqu'au caractere choisi
 */
size_t    ft_strlen(const char *s, int ascii)
{
    printf("string|%s|\n", s);
    size_t    i;

    if (!s)
        return (0);
    i = 0;
    while (s[i] != ascii)
        i++;
    printf("i|%zu|\n", i);
    return (i);
}

/*
 * return a pointer to the located character
 * or NULL if the character does not appear in the string
 */
char    *ft_strchr(const char *s, int c)
{
    int        i;

    if (!s)
        return (0);
    i = 0;
    while (s[i])
    {
        if (s[i] == (char)c)
            return ((char *)s + i);
        i++;
    }
    if (s[i] == (char)c)
        return ((char *)s + i);
    return (0);
}

/*
 * But ici : d'avoir notre *buffer, mais qui commence par les restes (*leftover)
 * retourne une nouvelle string mallocée qui concatene s1 + s2
 * free s1 car plus besoin, on a les infos dans s3
 * pas besoin de free buffer il est ecrase par read apres
 */
char    *ft_strjoin(char *s1, char *s2)
{
    char    *s3;
    int        i;
    int        j;

    if (!s1 || !s2)
        return (0);
    s3 = (char *)malloc((ft_strlen(s1, '\0') + ft_strlen(s2, '\0') + 1) * sizeof(char));
    if (!s3)
        return (NULL);
    i = -1;
    while (s1[++i])
        s3[i] = s1[i];
    j = -1;
    while (s2[++j])
        s3[i + j] = s2[j];
    s3[i + j] = '\0';
    free(s1);
    return (s3);
}

/*
 * permet de pouvoir retourner une chaine de caracteres vide
 * au lieu de NULL on a un tableau avec juste un \0 return ft_strdup("");
 */
char    *ft_strdup(const char *s1)
{
    char    *copy;
    int        i;

    copy = (char *)malloc((ft_strlen(s1, '\0') + 1) * sizeof(char));
    if (copy == NULL)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        copy[i] = s1[i];
        i++;
    }
    copy[i] = 0;
    return (copy);
}

char    *ft_substr(char *s, unsigned int start, size_t len)
{
    char    *str;
    size_t    i;

    if (!s)
        return (NULL);
    if (start > ft_strlen(s, '\0'))
        return (ft_strdup(""));
    if (len > ft_strlen(s, '\0') - start)
        len = ft_strlen(s, '\0') - start;
    str = (char *)malloc((len + 1) * sizeof(char));
    if (!str)
        return (NULL);
    i = 0;
    while (i < len)
        str[i++] = s[start++];
    str[i] = 0;
    return (str);
}

/*
 * pour pouvoir sortir de la fonction en faisant un free()
 */
char *ft_free(char *str)
{
    free(str);
    return (NULL);
}
