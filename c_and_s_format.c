#include "ft_printf_bonus.h"

int character_case(va_list *list, t_format *flg, int w_nbr)
{
    int count, c;
    count = 0;
    c = va_arg(*list, int);
    if(w_nbr != -1)
    {
        if(flg->minus_flag)
        {
            count += b_ft_putchar(c);
            while(--w_nbr > 0)
                count += b_ft_putchar(' ');
        }
        else
        {
            while(--w_nbr > 0)
                count += b_ft_putchar(' ');
            count += b_ft_putchar(c);
        }
    }
    else
        count += b_ft_putchar(c);
    return count;
}

int string_case_one(char *str, t_format *flg, int w_nbr, int len)
{
    int count;
    count = 0;

    w_nbr -= len;
    if(flg->minus_flag)
    {
        count += b_ft_putstr(str);
        while (w_nbr-- > 0)
            count += b_ft_putchar(' ');
    }
    else
    {
        while (w_nbr-- > 0)
            count += b_ft_putchar(' ');						
        count += b_ft_putstr(str);
    }
    return count;
}

int string_case_two(char *str, t_format *flg, int w_nbr, int p_nbr)
{
    int count;
    count = 0;

    w_nbr -= p_nbr;
    if(flg->minus_flag)
    {
        count += write(1, str, p_nbr);
        while (w_nbr-- > 0)
            count += b_ft_putchar(' ');
    }
    else
    {
        while (w_nbr-- > 0)
            count += b_ft_putchar(' ');
        count += write(1, str, p_nbr);
    }

    return count;
}

int string_case(va_list *list, t_format *flg, int w_nbr, int p_nbr)
{
    char *str;
    int len, count;
    count = 0;
    str = va_arg(*list, char *);
    len = b_ft_strlen(str);
    if((p_nbr >= 0 && p_nbr <= len && w_nbr > len)||(p_nbr >= 0 && p_nbr <= len && w_nbr <= len))
        count += string_case_two(str, flg, w_nbr, p_nbr);
    else if(w_nbr > len && w_nbr != -1)
        count += string_case_one(str, flg, w_nbr, len);
    else if(p_nbr <= len && p_nbr != -1)
        count += write(1, str, p_nbr);
    else
        count += b_ft_putstr(str);
    return count;
}
