/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:52:57 by hrahal            #+#    #+#             */
/*   Updated: 2025/10/29 14:23:45 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	sign_case(t_format *flg, int c)
{
	int	count;

	count = 0;
	if (c >= 0)
	{
		if (flg->plus_flag)
		{
			count += b_ft_putchar('+');
		}
		else if (flg->space_flag)
			count += b_ft_putchar(' ');
	}
	else
	{
		c *= -1;
		count += b_ft_putchar('-');
	}
	return (count);
}

int	number_case(va_list *list, t_format *flg, int w_nbr, int p_nbr)
{
	int	c;
	int	count;
	int	len;

	count = 0;
	c = va_arg(*list, int);
	len = b_num_len(c);
	if (w_nbr >= len && p_nbr >= len)
	{
		if (w_nbr <= p_nbr)
			count += number_case_two(flg, c, len, p_nbr);
		else
			count += number_case_three(flg, c, w_nbr, p_nbr);
	}
	else if (w_nbr >= len && w_nbr != -1)
		count += number_case_one(flg, c, p_nbr, w_nbr);
	else if (p_nbr > len && p_nbr != -1)
		count += number_case_two(flg, c, len, p_nbr);
	else
		count += number_edge_case1(flg, c, p_nbr);
	return (count);
}

int	number_case_one(t_format *flg, int c, int p_nbr, int w_nbr)
{
	int	count;
	int	len;

	len = b_num_len(c);
	count = 0;
	if ((flg->plus_flag) || (flg->space_flag) || (c < 0))
		w_nbr -= len + 1;
	else
		w_nbr -= len;
	if ((flg->plus_flag && flg->minus_flag) || (flg->space_flag
			&& flg->minus_flag) || (flg->plus_flag && flg->zero_flag)
		|| (flg->space_flag && flg->zero_flag))
		count += number_combined_flags(flg, w_nbr, p_nbr, c);
	else if ((flg->plus_flag) || (flg->minus_flag) || (flg->space_flag)
		|| (flg->zero_flag && p_nbr == -1))
		count += number_individual_flags(flg, w_nbr, p_nbr, c);
	else
		count += number_edge_case2(flg, c, w_nbr, p_nbr);
	return (count);
}

int	number_case_two(t_format *flg, int c, int len, int p_nbr)
{
	int	count;

	count = 0;
	p_nbr -= len;
	count += sign_case(flg, c);
	while (p_nbr-- > 0)
		count += b_ft_putchar('0');
	count += b_ft_putnbr(c);
	return (count);
}

int	number_case_three(t_format *flg, int c, int w_nbr, int p_nbr)
{
	int	len;
	int	count;

	count = 0;
	len = b_num_len(c);
	if ((flg->plus_flag) || (flg->space_flag) || (c < 0))
		w_nbr -= p_nbr + 1;
	else
		w_nbr -= p_nbr;
	p_nbr -= len;
	if ((flg->minus_flag && flg->plus_flag) || (flg->minus_flag
			&& flg->space_flag))
		count += number_combined_flags_2(flg, w_nbr, p_nbr, c);
	else if ((flg->plus_flag) || (flg->minus_flag) || (flg->space_flag))
		count += number_individual_flags_2(flg, w_nbr, p_nbr, c);
	else
	{
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
		count += sign_case(flg, c);
		while (p_nbr-- > 0)
			count += b_ft_putchar('0');
		count += b_ft_putnbr(c);
	}
	return (count);
}
