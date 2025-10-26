#include "ft_printf_bonus.h"
int u_number_case(va_list *list, t_format *flg, int w_nbr, int p_nbr)
{
    int len, count;
    unsigned int c;
    count = 0;
    
    c = va_arg(*list, unsigned int);
    len = b_unsigned_num_len(c);

    if(w_nbr > len && p_nbr > len)
    {
        if(w_nbr <= p_nbr)
            count += u_number_case_two(flg, c, p_nbr, len);
        else
            count += u_number_case_three(flg, c, w_nbr, p_nbr);
    }
    else if(w_nbr > len && w_nbr != -1)
        count += u_number_case_one(flg, c, w_nbr, len);
    else if (p_nbr > len && p_nbr != -1)
        count += u_number_case_two(flg, c, p_nbr, len);
    else
        count += b_ft_putnbr_unsigned(c);
    return count;
}

int u_number_case_one(t_format *flg, int c, int w_nbr, int len)
{
    int count;
    count = 0;

    w_nbr -= len;
    if(flg->minus_flag)
    {
        count += b_ft_putnbr_unsigned(c);
        while (w_nbr-- > 0)
            count += b_ft_putchar(' ');
    }
    else if (flg->zero_flag)
    {
        while (w_nbr-- > 0)
            count += b_ft_putchar('0');
        count += b_ft_putnbr_unsigned(c);
    }
    else
    {
        while (w_nbr-- > 0)
            count += b_ft_putchar(' ');
        count += b_ft_putnbr_unsigned(c);
    }
    return count;
}

int u_number_case_two(t_format *flg, int c, int p_nbr, int len)
{
    int count;
    count = 0;

    p_nbr -= len;
    while (p_nbr-- > 0)
        count += b_ft_putchar('0');
    count += b_ft_putnbr_unsigned(c);

    return count;
}

int u_number_case_three(t_format *flg, int c, int w_nbr, int p_nbr)
{
    int count, len;
    count = 0;
    len = b_unsigned_num_len(c);

    w_nbr -= p_nbr;
    p_nbr -= len;
    if (flg->minus_flag)
    {
        while (p_nbr-- > 0)
            count += b_ft_putchar('0');
        count += b_ft_putnbr_unsigned(c);
        while (w_nbr-- > 0)
            count += b_ft_putchar(' ');
    }
    else
    {
        while (w_nbr-- > 0)
            count += b_ft_putchar(' ');
        while (p_nbr-- > 0)
            count += b_ft_putchar('0');
        count += b_ft_putnbr_unsigned(c);
    }
    return count;
}

