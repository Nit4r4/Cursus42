/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:25:09 by lgenevey          #+#    #+#             */
/*   Updated: 2021/10/19 20:58:12 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stddef.h>

/*
 * c must be unsigned char or the value of EOF 
 * returns zero if the character tests false and returns non-zero if the character tests true 
*/
int		ft_isalpha(int c);

/*
 * Only 0 1 2 3 4 5 6 7 8 9. (char, not integer)
 * Function "isnumber" works with additional characters depending on the current locale stting.
 * returns zero if the character tests false, non-zero if the character tests true
 */
int		ft_isdigit(int d);

/*
 * unsigned char or value of EOF
 * returns zero if the tests are false, 1 if tests are true
 */
int		ft_isalnum(int c);

/*
 * check if c is a char in ascii table, in a range 0 to 127.
 * 1 if it's true, 0 if not
 */
int		ft_isascii(int c);

/*
 * check if it's a printed char. Space included (32). Delete not included (127)
 * returns 1 if it's printable, 0 if not
 */
int		ft_isprint(int c);

/*
 * Compute the length of the string s but never beyond the first maxlen byte of s.
 * returns the number of characters before the NULL character. ('\0' not included)
 */
long	ft_strlen(const char *s);

/*
 * remplir une zone memoire, identifiee par son adresse et sa taille avec une valeur
 * precise
 * pointer : permet de specifier l'adresse du bloc memoire a reset
 * value : indique la valeur a utiliser pour remplir le bloc de memoire
 * size : indique le nombre d'octets a initialiser
 */
void	*ft_memset(void *pointer, int value, size_t size);

/*
 * met a 0 (octets contenant \0) les n premiers octets du bloc pointe par s
 * s : adresse de depart de la zone de memoire
 * n : nombre d'octets qui doivent etre mis a 0
 * if n is zero, the function does nothing
 */
void	ft_bzero(void *s, size_t n);

/*
 * Copie les n octets de src vers dest. Si la source et la destination se chevauchent,
 * le comportement de memcpy n'est pas defini. Utiliser memmove pour gerer les regions qui se
 * chevauchent
 * returns a pointer to dest
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/*
 * Cette fonction permet de copier un bloc de mémoire spécifié par le paramètre source 
 * dans un nouvel emplacement désigné par le paramètre destination. 
 * On peut donc dire que cette fonction est proche de la fonction memcpy. 
 * Néanmoins, la différence réside dans le fait que la fonction memmove accepte que les 
 * deux zones de mémoire puissent se chevaucher. 
 * En cas de chevauchement : la copie se passe comme si les octets de la zone source etaient
 * d'abord copies dans une zone temporaire, et ensuite copies de la zone temp a la zone de 
 * destination.
 *
 * retourne l'adresse du bloc de memoire de destination
 *
 * destination : permet de spécifier l'adresse du bloc mémoire devant recevoir les données à copier.
 * source : permet de définir l'adresse du bloc de mémoire à dupliquer.
 * size : indique le nombre d'octets à dupliquer.
 */
void	*ft_memmove(void *dest, const void *src, size_t len);

/*
 * Certain systemes BSD, Solaris..) fournissent cette fonction.
 * Similaire a strcpy, mais va copier au moins "size-1" octet a dest
 * Attention si la taille est trop petite
 * returns : length of src, which allows truncation to be easily detected: if the return value is 
 * greater than or equal to size, truncation occurred. 
 * If loss of data matters, the caller must either check the arguments before the call, or test 
 * the function return value.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);

/*
 * convert minuscule to majuscule, only ASCII.
 * int c : un int car on accepte la valeur -1 (End Of FIle - fin d'un flux)
 * retourne : caractere equivalent en majuscule
 */
int		ft_toupper(int c);

/*
 * convert maj to minus
 */
int		ft_tolower(int c);

/*
 * search the FIRST occurence of the character. strrchr : search the LAST character, r is for
 * searching from right side.(donc le premier char depuis la fin du tableau en gros).
 * returns a pointer to the located character or NULL if it does not appear.
 * c : le caractere recherche
 */
char	*ft_strchr(const char *s, int c);

/*
 * search if c is in s, from the end
 * returns adress where c is located or NULL if it's not
 */
char	*ft_strrchr(const char *s, int c);

/*
 * compare deux chaines de caracteres et indique si la premiere est inferieure, egale ou superieure
 * a la seconde. Ordre des valeures ASCII des caracteres compares. Ici la comparaison se fait sur les n
 * premiers caracteres
 * s1 : premiere chaine a comparer
 * s2 : seconde chaine a comparer
 * n  : nombre maximal de caracteres a comparer
 * retourne : 0 si identique | positif si s1 > s2 | negatif si s1 < s2
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
 * s : adresse du bloc memoire a utiliser pour la recherche
 * c : code numerique de l'octet a rechercher dans le bloc
 * n : taille du bloc de memoire dans lequel operer la recherche
 * retourne : si la fonction trouve le char recherche, renvoie un pointeur vers sa premiere occurence
 * 			  sinon renvoie NULL
 */
void	*ft_memchr(const void *s, int c, size_t n);

/*
 * 0 : s1 and s2 are equal
 * Negative integer : The stopping character in s1 was less than the stopping character in s2
 * Positive integer : The stopping character in s1 was greater than the stopping character in s2
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
 * haystack : la string dans laquelle faire la recherche
 * needle 	: premiere occurence d'une string
 * len		: nb de char a comparer
 * retourne : si needle est trouve dans haystack, retourne l'adresse de la premiere occurence
 * 			  sinon retourne un pointeur sur NULL. 
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif


