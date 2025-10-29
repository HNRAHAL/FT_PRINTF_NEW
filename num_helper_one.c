/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_helper_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:57:08 by hrahal            #+#    #+#             */
/*   Updated: 2025/10/29 15:12:32 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	width_padding(int w_nbr)
{
	int	count;

	count = 0;
	while (w_nbr-- > 0)
		count += b_ft_putchar(' ');
	return (count);
}

int	number_combined_flags(t_format *flg, int w_nbr, int p_nbr, int c)
{
	int	count;

	count = 0;
	if (p_nbr != -1)
		count += number_edge_case5(flg, c, w_nbr, p_nbr);
	else
	{
		if ((flg->plus_flag && flg->minus_flag) || (flg->space_flag
				&& flg->minus_flag))
		{
			count += sign_case(flg, c);
			count += b_ft_putnbr(c);
			count += width_padding(w_nbr);
		}
		else if ((flg->plus_flag && flg->zero_flag) || (flg->space_flag
				&& flg->zero_flag))
		{
			count += sign_case(flg, c);
			while (w_nbr-- > 0)
				count += b_ft_putchar('0');
			count += b_ft_putnbr(c);
		}
	}
	return (count);
}

int	number_individual_flags(t_format *flg, int w_nbr, int p_nbr, int c)
{
	int	count;

	count = 0;
	if (flg->plus_flag || flg->space_flag)
		count += number_edge_case6(flg, c, w_nbr, p_nbr);
	else if (flg->minus_flag)
		count += number_edge_case7(flg, c, w_nbr, p_nbr);
	else if (flg->zero_flag)
	{
		count += sign_case(flg, c);
		while (w_nbr-- > 0)
			count += b_ft_putchar('0');
		count += b_ft_putnbr(c);
	}
	return (count);
}
