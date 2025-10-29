#include "ft_printf_bonus.h"

int x_lower_number_else_case2(t_format *flg, char *str, int w_nbr, int p_nbr)
{
    int count, len;

    count = 0;
    len = b_ft_strlen(str);
    w_nbr += 2;
    if(flg->minus_flag)
    {
        while(p_nbr-- > 0)
            count += b_ft_putchar('0');
        while (len-- > 0)
            count += write(1, &str[len], 1);
        while(w_nbr-- > 0)
            count += b_ft_putchar(' ');
    }
    else
    {
        while(w_nbr-- > 0)
            count += b_ft_putchar(' ');
        while(p_nbr-- > 0)
            count += b_ft_putchar('0');
        while (len-- > 0)
            count += write(1, &str[len], 1);
    }
    return count;
}

int lower_zero_case2(t_format *flg, int w_nbr, int p_nbr)
{
    int count;
    count = 0;
    
	w_nbr -= p_nbr;
    p_nbr -= 1;
    if(flg->minus_flag)
    {
        count += b_ft_putchar('0');
        while(p_nbr-- > 0)
            count += b_ft_putchar('0');
        while(w_nbr-- > 0)
            count += b_ft_putchar(' ');
    }
    else
    {
        while(w_nbr-- > 0)
            count += b_ft_putchar(' ');
        while(p_nbr-- > 0)
            count += b_ft_putchar('0');
        count += b_ft_putchar('0');
    }
    return count;
}

int x_lower_number_combined_flags2(t_format *flg,char *str,int w_nbr,int p_nbr)
{
    int count, len;

    count = 0;
    len = b_ft_strlen(str);
    if(flg->minus_flag && flg->hash_flag)
    {
        count += b_ft_putstr("0x");
        while(p_nbr-- > 0)
            count += b_ft_putchar('0');
        while (len-- > 0)
            count += write(1, &str[len], 1);
        while(w_nbr-- > 0)
            count += b_ft_putchar(' ');
    }
    else if(flg->hash_flag)
    {
        while(w_nbr-- > 0)
            count += b_ft_putchar(' ');
        count += b_ft_putstr("0x");
        while(p_nbr-- > 0)
            count += b_ft_putchar('0');
        while (len-- > 0)
            count += write(1, &str[len], 1);
    }
    return count;
}