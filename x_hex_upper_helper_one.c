/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_hex_upper_helper_one.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 12:33:34 by hrahal            #+#    #+#             */
/*   Updated: 2025/10/28 17:28:22 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	x_upper_number_else_case(t_format *flg, char *str, int w_nbr, int len)
{
	int	count;

	count = 0;
	w_nbr += 2;
	if (flg->minus_flag)
	{
		while (len-- > 0)
			count += write(1, &str[len], 1);
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
	}
	else
	{
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
		while (len-- > 0)
			count += write(1, &str[len], 1);
	}
	return (count);
}

int	upper_zero_case(t_format *flg, int w_nbr)
{
	int	count;

	count = 0;
	w_nbr -= 1;
	if (flg->minus_flag)
	{
		count += b_ft_putchar('0');
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
	}
	else if (flg->zero_flag)
	{
		while (w_nbr-- > 0)
			count += b_ft_putchar('0');
		count += b_ft_putchar('0');
	}
	else
	{
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
		count += b_ft_putchar('0');
	}
	return (count);
}

int	x_upper_number_combined_flags(t_format *flg, unsigned int num, int w_nbr, int p_nbr)
{
    int count, len;
    char *str;

    str = b_return_hexvalue_upper(num);
    len = b_ft_strlen(str);
    count = 0;
	
	if ((flg->minus_flag && flg->hash_flag))
	{
		count += b_ft_putstr("0X");
		while (len-- > 0)
			count += write(1, &str[len], 1);
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
	}
	else if (flg->zero_flag && flg->hash_flag)
	{
		if(p_nbr != -1)
        {
            while(w_nbr-- > 0)
                count += b_ft_putchar(' ');
            count += b_ft_putstr("0X");
            while(len-- > 0)
                count += write(1, &str[len], 1);
        }
        else
        {
            count += b_ft_putstr("0X");
            while(w_nbr-- > 0)
                count += b_ft_putchar('0');	
            while(len-- > 0)
                count += write(1, &str[len], 1);
        }
	}
	free(str);
	return (count);
}
