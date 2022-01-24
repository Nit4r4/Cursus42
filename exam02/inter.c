/*

Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Écrire un programme qui prend en paramètres deux chaînes de caractères et qui
affiche sans doublon les caractères communs aux deux chaînes.

L'affichage se fera dans l'ordre d'apparition dans la premiere chaîne.
L'affichage doit être suivi d'un '\n'.

Si le nombre de paramètres transmis est différent de 2, le programme affiche
'\n'.

Exemples:
$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$

*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	table[128];
	int		i, j;

	if (argc == 3)
	{
		i = 0;
		while (table[i])
		{
			table[i] = 0;
			i++;
		}
		i = 2;
		while (i > 0)
		{
			j = 0;
			while (argv[i][j])
			{
				if (i == 2 && !table[(unsigned char)argv[i][j]])
					table[(unsigned char)argv[i][j]] = 1;
				else if (i == 1 && table[(unsigned char)argv[i][j]] == 1)
				{
					write(1, &argv[i][j], 1);
					table[(unsigned char)argv[i][j]] = 2;
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}