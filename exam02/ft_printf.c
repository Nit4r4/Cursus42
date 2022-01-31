#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/* writes a char and return 1 */
int ft_putchar(char c)
{
    return write(1, &c, 1);
}

/* writes *s and return nb of letters written */
int ft_putstr(char *s)
{
    int i;

    if (!s)
        return (write(1, "(null)", 6));
    i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    return (i);
}

/* writes n and return nb of digit written */
int ft_putnbr(long int n)
{
    int count;

    count = 0;
    if (n < 0)
    {
        count += ft_putchar('-');
        n *= -1;
    }
    if (n > 9)
        count += ft_putnbr(n / 10);
    count += ft_putchar(n % 10 + '0');
    return (count);
}

/* convert decimal into hexadecimal, writes it and return nb of digit written */
int ft_puthexa(unsigned int n)
{
    int     count;
    char    *table;

    count = 0;
    table = "0123456789abcdef";
    if (n > 15)
        count += ft_puthexa(n / 16);
    count += ft_putchar(table[n % 16]);
    return (count);
}

/* exam02 ft_printf */
int ft_printf(const char *str, ...)
{
    va_list args;
    int     count;

    va_start(args, str);
    count = 0;
    if (!str)
        return (0);
    while (*str)
    {
        if (*str != '%')
            count += write(1, str, 1);
        else
        {
            str++;
            if (*str == '%')
                count += write(1, "%", 1);
            else if (*str == 'c')
                count += ft_putchar((char)va_arg(args, int));
            else if (*str == 's')
                count += ft_putstr(va_arg(args, char *));
            else if (*str == 'd')
                count += ft_putnbr(va_arg(args, int));
            else if (*str == 'x')
                count += ft_puthexa(va_arg(args, unsigned int));
        }
        str++;
    }
    va_end(args);
    return (count);
}

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
