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
    if (nbr < 0)
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
    table = "0123456789abcdef":
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
        if (str != '%')
            count += write(1, str, 1);
        else
        {
            str++;
            //ft_norminette(*str, &count, args);
            if (c == '%')
                count += write(1, '%', 1);
            else if (c == 'c')
                count += ft_putchar((char*)va_arg(args, int);
            else if (c == 's')
                count += ft_putstr((char *)va_arg(args, char *));
            else if (c == 'd' || c == 'i')
                count += ft_putnbr(va_arg(args, int));
            else if (c == 'x')
                count += ft_putbase(va_arg(args, unsigned int));
        }
        str++;
    }
    va_end(args);
    return (count);
}