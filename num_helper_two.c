/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_helper_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:57:46 by hrahal            #+#    #+#             */
/*   Updated: 2025/10/29 10:07:02 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	number_individual_flags_2(t_format *flg, int w_nbr, int p_nbr, int c)
{
	int	count;

	count = 0;
	if ((flg->plus_flag) || (flg->space_flag))
	{
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
		count += sign_case(flg, c);
		while (p_nbr-- > 0)
			count += b_ft_putchar('0');
		count += b_ft_putnbr(c);
	}
	else if (flg->minus_flag)
	{
		count += sign_case(flg, c);
		while (p_nbr-- > 0)
			count += b_ft_putchar('0');
		count += b_ft_putnbr(c);
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
	}
	return (count);
}

int	number_combined_flags_2(t_format *flg, int w_nbr, int p_nbr, int c)
{
	int	count;

	count = 0;
	count += sign_case(flg, c);
	while (p_nbr-- > 0)
		count += b_ft_putchar('0');
	count += b_ft_putnbr(c);
	while (w_nbr-- > 0)
		count += b_ft_putchar(' ');
	return (count);
}
