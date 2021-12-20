/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:09:57 by lgenevey          #+#    #+#             */
/*   Updated: 2021/12/20 16:16:01 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
---- GET_NEXT_LINE ----
decscription :
write a function which returns a line read from a file descriptor
arguments :
fd : file descriptor, id unique du fichier a lire. Le 0 1 et 2 sont reserves
pour les entrees et sorties std et les erreurs
la prochaine ligne lue

---- READ ----
decscription :
tente de lire nbytes de donnees de l'objet référencé par le descripteur
dans le tampon pointé par buf.
arguments :
fd : file descriptor, fichier ouvert.
*buffer : tableau qui contient les nbytes lues. Tampon qui garde l'eventuel
surplus que demande BUFFER_SIZE.
nbytes : le nombre d'octets a lire a la fois
valeurs de retour :
nbytes caracteres selon le BUFFER_SIZE donné
0 quand on arrive en fin de fichier
-1 si erreur rencontrée
*/

/*
gcc -Wall -Wextra -Werror *.c -g
lldb ./a.out
run
b : breakpoint
b [function_name]
b -l || b --line : breakpoint par rappot a la ligne
display
c : continue

*/

#include "get_next_line.h"
#include <stdio.h>

// faire revenir buffer a l'index 0 (ft_memmove)
// static sur i

char    *get_next_line(int fd)
{    // utiliser une variable preprocesseur est ok : buffer[BUFFER_SIZE + 1]
    // plus besoin de free comme ca.
    // static initialisee a zero par defaut
    char        *buffer; // stockage remplit par read
    char        *line; // la ligne propre
    static char    *leftover = NULL; // garde les laisses pour compte
    ssize_t        been_read; //nb de caracteres lus

    // stop si pas de fichier ou si on indique pas le nb de caracteres a lire
    if (fd < 0 || BUFFER_SIZE <= 0 || !fd)
        return (NULL);
    buffer = (char *)malloc((BUFFER_SIZE + 1) *sizeof(char));
    if (!buffer)
        return (NULL);
    //remplir buffer et stocker le retour de read()
    been_read = read(fd, buffer, BUFFER_SIZE);
    if (been_read < 1)
        return (ft_free(buffer));
    // tant que l'on n'a pas une ligne complete dans leftover
    // et qu'on n'est pas a la fin du fichier
    // - aussi on veut en sortir de la boucle si leftover est une ligne complete qui se fini pas par \n -
    // en comparant la taille du BUFFER_SIZE avec son retour. Si retour (been_read) plus petit alors on a fini avant donc on a une ligne complete
    while (!ft_strchr(leftover, '\n') || been_read < 1)
    {
        // on connait le nb de caracteres lus, = taille de buffer = been_read
        // du coup on peut mettre le \0 si je n'utilise pas calloc
        buffer[been_read] = '\0';
        // si premier passage donc leftover vide
        if (!leftover)
            // leftover va valoir buffer anyway, pas besoin de concatener
            leftover = ft_strdup(buffer);
        // si on lit moins que le BUFFER_SIZE c'est qu'on s'arrete de lire avant et donc c'est sur on a tout lu
        // on risque rien on est dans cette boucle car pas de \n anyway
        //else if (been_read < BUFFER_SIZE)
        //    return (ft_strdup(buffer));
        // sinon bah on concatene les restes avec le nouveau buffer
        else
            // stocker les restes de buffer dans leftover pour pas perdre
            // au prochain appel de gnl
            // le leftover devient "le buffer de travail" de guillaume
            // leftover en argument est initialise pour un premier passage au-dessus
            leftover = ft_strjoin(leftover, buffer);
        //remplir buffer et stocker le retour de read()
        been_read = read(fd, buffer, BUFFER_SIZE);
        if (been_read < 1)
            return (ft_free(buffer));
    }
    // plus besoin du buffer on le tej
    free(buffer);
    buffer = NULL;
    line = ft_substr(leftover, 0, ft_strlen(leftover, '\n') + 1); //LEAKS
    leftover = ft_substr(leftover, ft_strlen(leftover, '\n') + 1, ft_strlen(leftover, '\0') - ft_strlen(leftover, '\n'));
    return (line);
}

// fonction qui retourne line et leftover
// regler si been_read < BUFFER_SIZE : ok mais pas avec BS = 1
// regler le comptage et la copie
