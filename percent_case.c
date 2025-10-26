#include "ft_printf_bonus.h"

int percent_case(t_format *flg, int w_nbr, int len)
{
    int count;
    count = 0;
    
    if (w_nbr == -1)
        count += b_ft_putchar('%');
    else
    {
        if (flg->minus_flag)
        {
            count += b_ft_putchar('%');
            while ((--(w_nbr)) > 0)
                count += b_ft_putchar(' ');
        }
        else
        {
            while (--(w_nbr) > 0)
                count += b_ft_putchar(' ');
            count += b_ft_putchar('%');
        }
    }
    return count;
}