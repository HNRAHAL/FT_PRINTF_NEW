#include "ft_printf_bonus.h"

int p_else_case(char *str, int w_nbr, int p_nbr)
{
    int count, len;

    count = 0;
    len = b_ft_putstr(str);
    while (w_nbr-- > 0)
        count += b_ft_putchar(' ');
    count += b_ft_putstr("0x");
    while (p_nbr-- > 0)
        count += b_ft_putchar('0');
    while (len-- > 0)
        count += write(1, &str[len], 1);
    return count;
}

int p_else_case2( char *str, int len)
{
    int count;

    count = 0;
    count += b_ft_putstr("0x");
    while (len-- > 0)
        count += write(1, &str[len], 1);
    return count;
}