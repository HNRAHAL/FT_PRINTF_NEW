#include "ft_printf_bonus.h"

int number_combined_flags(t_format *flg, int w_nbr ,int c)
{
    int count;
    count = 0;
    if((flg->plus_flag && flg->minus_flag) || (flg->space_flag && flg->minus_flag))
    {
        count += sign_case(flg, c);
        count += b_ft_putnbr(c);
        while (w_nbr-- > 0)
            count += b_ft_putchar(' ');

    }
    else if((flg->plus_flag && flg->zero_flag) || (flg->space_flag && flg->zero_flag))
    {
        count += sign_case(flg, c);
        while (w_nbr-- > 0)
            count += b_ft_putchar('0');
        count += b_ft_putnbr(c);
    }
    return count;
}
int number_individual_flags(t_format *flg, int w_nbr ,int c)
{
    int count;
    count = 0;
    if(flg->plus_flag || flg->space_flag)
    {
        while (w_nbr-- > 0)
            count += b_ft_putchar(' ');
        count += sign_case(flg, c);
        count += b_ft_putnbr(c);
    }
    else if(flg->minus_flag)
    {
        count += sign_case(flg, c);
        count += b_ft_putnbr(c);
        while (w_nbr-- > 0)
            count += b_ft_putchar(' ');
    }

    else if(flg->zero_flag)
    {
        count += sign_case(flg, c);
        while (w_nbr-- > 0)
            count += b_ft_putchar('0');
        count += b_ft_putnbr(c);
    }
    return count;
}

