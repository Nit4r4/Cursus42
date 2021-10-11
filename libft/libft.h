/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:25:09 by lgenevey          #+#    #+#             */
/*   Updated: 2021/10/11 18:25:43 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * c must be unsigned char or the value of EOF 
 * returns zero if the character tests false and returns non-zero if the character tests true 
*/
int	ft_isalpha(int c);

/*
 * Only 0 1 2 3 4 5 6 7 8 9. (char, not integer)
 * Function "isnumber" works with additional characters depending on the current locale stting.
 * returns zero if the character tests false, non-zero if the character tests true
 */
int	ft_isdigit(int d);

/*
 * unsigned char or value of EOF
 * returns zero if the tests are false, 1 if tests are true
 */
int	ft_isalnum(int c);

/*
 * check if c is a char in ascii table, in a range 0 to 127.
 * 1 if it's true, 0 if not
 */

int	ft_isascii(int c);

/*
 * check if it's a printed char. Space included (32). Delete not included (127)
 * returns 1 if it's printable, 0 if not
 */

int	ft_isprint(int c);



