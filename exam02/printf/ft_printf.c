#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int ft_putchar(char c)
{
    return write(1, &c, 1);
}


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
            //ft_norminette(*str, &count, args);
            if (*str == '%')
                count += write(1, "%", 1);
            else if (*str == 'c')
                count += ft_putchar((char)va_arg(args, int));
            else if (*str == 's')
                count += ft_putstr((char *)va_arg(args, char *));
            else if (*str == 'd' || *str == 'i')
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
	char	*s = "salut";
	int		d = 10;

	printf("Salut\n");
	printf("%%s : %s", s);
	printf("%%d : %d\n", d);
	printf("%%x : %x\n", d);

	ft_printf("Salut\n");
	ft_printf("%%s : %s", s);
	ft_printf("%%d : %d\n", d);
	ft_printf("%%x : %x\n", d);

	return (0);
}
