#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	*s = "Hey";
	int		d = -10;
	int		fret = 0;
	int		ret = 0;

	printf("Salut\n");
	printf("%%s : %s\n", s);
	ret = printf("%%d : %d\n", d);
	printf("%%x : %x\n", d);
	printf("ret printf: %d\n", ret);

	ft_printf("Salut\n");
	ft_printf("%%s : %s\n", s);
	fret = printf("%%d : %d\n", d);
	ft_printf("%%x : %x\n", d);
	printf("ret ft_printf: %d\n", fret);

	return (0);
}
