/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_hex_upper_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 12:11:26 by hrahal            #+#    #+#             */
/*   Updated: 2025/10/28 17:27:44 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	x_upper_else_number_case(t_format *flg, char *str, unsigned int num,
		int len)
{
	int	count;

	count = 0;
	if (num == 0)
		count += b_ft_putchar('0');
	else if (flg->hash_flag)
		count += b_ft_putstr("0X");
	while (len-- > 0)
		count += write(1, &str[len], 1);
	return (count);
}

int	x_upper_number_case(va_list *list, t_format *flg, int w_nbr, int p_nbr)
{
	unsigned int	num;
	char			*str;
	int				len;
	int				count;

	count = 0;
	num = va_arg(*list, unsigned int);
	str = b_return_hexvalue_upper(num);
	len = b_ft_strlen(str);
	if (w_nbr > len && p_nbr > len)
	{
		if (w_nbr <= p_nbr)
			count += x_upper_number_case_two(flg, str, num, p_nbr);
		else
			count += x_upper_number_case_three(flg, num, w_nbr, p_nbr);
	}
	else if (w_nbr > len && w_nbr != -1)
		count += x_upper_number_case_one(flg, p_nbr, num, w_nbr);
	else if (p_nbr > len && p_nbr != -1)
		count += x_upper_number_case_two(flg, str, num, p_nbr);
	else
	{
		if(num == 0 && p_nbr == 0);
		else
        	count += x_upper_else_number_case(flg, str, num, len);
	}
	free(str);
	return (count);
}

int	x_upper_number_case_one(t_format *flg, int p_nbr , unsigned int num,
		int w_nbr)
{
	int	count;
	int	len;
	char *str;
	
	count = 0;
	str = b_return_hexvalue_upper(num);
	len = b_ft_strlen(str);
	if(num == 0)
	{
		if(p_nbr == 0 && w_nbr != -1)
		{
			while(w_nbr-- > 0)
				count += b_ft_putchar(' ');
		}
		else
        	count += upper_zero_case(flg, w_nbr);
	}
	else
	{
		w_nbr -= len + 2;
		if ((flg->minus_flag && flg->hash_flag) || (flg->zero_flag
				&& flg->hash_flag))
			count += x_upper_number_combined_flags(flg, num, w_nbr, p_nbr);
		else if (flg->hash_flag)
		{
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
			count += b_ft_putstr("0X");
			while (len-- > 0)
				count += write(1, &str[len], 1);
		}
		else if (flg->zero_flag && p_nbr != -1)
		{
			w_nbr += 2;
			while(w_nbr-- > 0)
                count += b_ft_putchar(' ');
			while(len-- > 0)
                count += write(1, &str[len], 1);
		}
		else if (flg->zero_flag )
		{
			w_nbr += 2;
			while(w_nbr-- > 0)
                count += b_ft_putchar('0');
			while(len-- > 0)
                count += write(1, &str[len], 1);
		}
		else
			count += x_upper_number_else_case(flg, str, w_nbr, len);
	}
	free(str);
	return (count);
}

int	x_upper_number_case_two(t_format *flg, char *str, unsigned int num,
		int p_nbr)
{
	int	count;
	int	len;

	count = 0;
	len = b_ft_strlen(str);
	if (num == 0)
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
			b_ft_putstr("0X");
			count += 2;
		}
		while (p_nbr-- > 0)
			count += b_ft_putchar('0');
		while (len-- > 0)
			count += write(1, &str[len], 1);
	}
	return (count);
}

int	x_upper_number_case_three(t_format *flg, unsigned int num, int w_nbr,
		int p_nbr)
{
	int		count;
	int		len;
	char	*str;

	count = 0;
	str = b_return_hexvalue_upper(num);
	len = b_ft_strlen(str);
	if (num == 0)
		count += upper_zero_case2(flg, w_nbr, p_nbr);
	else
	{
		w_nbr -= p_nbr + 2;
		p_nbr -= len;
		if ((flg->minus_flag && flg->hash_flag) || (flg->hash_flag))
			count += x_upper_number_combined_flags2(flg, str, w_nbr, p_nbr);
		else
			count += x_upper_number_else_case2(flg, str, w_nbr, p_nbr);
	}
	free(str);
	return (count);
}
