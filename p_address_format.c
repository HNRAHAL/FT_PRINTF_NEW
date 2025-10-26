#include "ft_printf_bonus.h"

int p_number_case(va_list *list, t_format *flg,int w_nbr, int p_nbr)
{
    void	*ptr;
    char    *str;
    int     len, count;

    count = 0;
    ptr = va_arg(*list, void *);
    str = b_return_address_and_convert_to_hex(ptr);
    len = b_ft_strlen(str);	
    if(w_nbr > len && p_nbr > len)	
    {
        if(w_nbr <= p_nbr)
            count += p_number_case_two(str, p_nbr, len);
        else
            count += p_number_case_three(flg, str, w_nbr, p_nbr); 
    }
    else if(w_nbr > len && w_nbr != -1)
        count += p_number_case_one(flg, str, w_nbr, len);
    else if(p_nbr > len && p_nbr != -1)
        count += p_number_case_two(str, p_nbr, len);

    else
        count += p_else_case2(str, len);
    return count;
}

int p_number_case_one(t_format *flg, char *str, int w_nbr, int len)
{
    int count;
    count = 0;
    if (flg->minus_flag)
    {
        count += b_ft_putstr("0x");
        while (len-- > 0)
            count += write(1, &str[len], 1);
        while (w_nbr-- > 0)
            count += b_ft_putchar(' ');
    }
    else
    {
        while (w_nbr-- > 0)
            count += b_ft_putchar(' ');
        count += b_ft_putstr("0x");
        while (len-- > 0)
            count += write(1, &str[len], 1);
    }
    return count;
}

int p_number_case_two(char *str, int p_nbr, int len)
{
    int count;
    count = 0;

    p_nbr -= len;
    count += b_ft_putstr("0x");
    while (p_nbr-- > 0)
        count += b_ft_putchar('0');
    while (len-- > 0)
        count += write(1, &str[len], 1);
    return count;
}

int p_number_case_three(t_format *flg, char *str, int w_nbr, int p_nbr)
{
    int count,len;

    len = b_ft_strlen(str);
    count = 0;
    w_nbr -= p_nbr + 2;
    p_nbr -= len;
    if (flg->minus_flag)
    {
        count += b_ft_putstr("0x");
        while (p_nbr-- > 0)
            count += b_ft_putchar('0');
        while (len-- > 0)
            count += write(1, &str[len], 1);
        while (w_nbr-- > 0)
            count += b_ft_putchar(' ');
    }
    else
        count += p_else_case(str,w_nbr,p_nbr);
    return count;
}

