#include "ft_printf_bonus.h"
int x_lower_else_number_case(t_format *flg, char *str, unsigned int num, int len)
{
    int count;
    count = 0;

    if(num == 0)
        count += b_ft_putchar('0');
    else if(flg->hash_flag)
        count += b_ft_putstr("0x");
    while(len-- > 0)
        count += write(1, &str[len], 1);
    return count;
}
int x_lower_number_case(va_list *list, t_format *flg, int w_nbr, int p_nbr)
{
    int len, count;
    unsigned int num;
    char *str;

    count = 0;
    num = va_arg(*list, unsigned int);
    str = b_return_hexvalue_lower(num);
    len = b_ft_strlen(str);
    if(w_nbr > len && p_nbr > len)
    {
        if(w_nbr <= p_nbr)
            count += x_lower_number_case_two(flg, str, num, p_nbr);
        else
            count += x_lower_number_case_three(flg,num,w_nbr,p_nbr);
    }
    else if(w_nbr > len && w_nbr != -1)
        count += x_lower_number_case_one(flg, str , num, w_nbr);
    else if(p_nbr > len && p_nbr != -1)
        count += x_lower_number_case_two(flg, str, num, p_nbr);
    else 
        count += x_lower_else_number_case(flg, str, num, len);
    return count;
}

int x_lower_number_case_one(t_format *flg, char *str ,unsigned int num, int w_nbr)
{
    int count, len;

    count = 0;
    len = b_ft_strlen(str);
    if(num == 0)
        count += lower_zero_case(flg, w_nbr);
    else
    {		
        w_nbr -= len + 2;
        if((flg->minus_flag && flg->hash_flag)||(flg->zero_flag && flg->hash_flag))
            count += x_lower_number_combined_flags(flg, str, w_nbr, len);
        else if(flg->hash_flag)
        {
            while(w_nbr-- > 0)
                count += b_ft_putchar(' ');
            count += b_ft_putstr("0x");
            while(len-- > 0)
                count += write(1, &str[len], 1);
        }
        else
            count += x_lower_number_else_case(flg, str, w_nbr, len);
    }
    return count;
}

int x_lower_number_case_two(t_format *flg, char *str ,unsigned int num, int p_nbr)
{
    int count, len;

    count = 0;
    len = b_ft_strlen(str);
    if(num == 0)
    {
        p_nbr -= len + 1;
        while (p_nbr-- > 0)
            count += b_ft_putchar('0');
        count += b_ft_putchar('0');
    }
    else
    {	
        p_nbr -= len;
        if (flg->hash_flag)
        {
            b_ft_putstr("0x");
            count += 2;
        }
        while (p_nbr-- > 0)
            count += b_ft_putchar('0');
        while (len-- > 0)
            count += write(1, &str[len], 1);
    }
    return count;
}

int x_lower_number_case_three(t_format *flg, unsigned int num, int w_nbr, int p_nbr)
{
    int count, len;
    char *str;
    count = 0;
    
    str = b_return_hexvalue_lower(num);
    len = b_ft_strlen(str);

    if(num == 0)
        count += lower_zero_case2(flg, w_nbr, p_nbr);
    else
    {
		w_nbr -= p_nbr + 2;
        p_nbr -= len;

        if((flg->minus_flag && flg->hash_flag)||(flg->hash_flag))
            count += x_lower_number_combined_flags2(flg, str, w_nbr, p_nbr);
        else
            count += x_lower_number_else_case2(flg, str, w_nbr, p_nbr);
    }
    return count;
}
