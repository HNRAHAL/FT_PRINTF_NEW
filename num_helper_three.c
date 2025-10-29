/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_helper_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:14:54 by hrahal            #+#    #+#             */
/*   Updated: 2025/10/29 15:14:55 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	number_edge_case3(t_format *flg, int c, int w_nbr, int p_nbr)
{
	int	count;

	count = 0;
	if (c == 0 && w_nbr != -1 && p_nbr == 0)
	{
		w_nbr += 1;
		count += sign_case(flg, c);
		count += width_padding(w_nbr);
	}
	else
	{
		if (c == 0)
		{
			count += sign_case(flg, c);
			count += width_padding(w_nbr);
		}
		else
		{
			count += sign_case(flg, c);
			count += b_ft_putnbr(c);
			count += width_padding(w_nbr);
		}
	}
	return (count);
}

int	number_edge_case4(t_format *flg, int c, int w_nbr, int p_nbr)
{
	int	count;

	count = 0;
	if (c == 0 && w_nbr != -1 && p_nbr == 0)
	{
		w_nbr += 1;
		count += width_padding(w_nbr);
		count += sign_case(flg, c);
	}
	else
	{
		if (c == 0)
		{
			count += width_padding(w_nbr);
			count += sign_case(flg, c);
		}
		else
		{
			count += width_padding(w_nbr);
			count += sign_case(flg, c);
			count += b_ft_putnbr(c);
		}
	}
	return (count);
}

int	number_edge_case5(t_format *flg, int c, int w_nbr, int p_nbr)
{
	int	count;

	count = 0;
	if (((flg->plus_flag && flg->minus_flag) || (flg->space_flag
				&& flg->minus_flag)))
		count += number_edge_case3(flg, c, w_nbr, p_nbr);
	else if (((flg->space_flag && flg->zero_flag) || (flg->plus_flag
				&& flg->zero_flag)))
		count += number_edge_case4(flg, c, w_nbr, p_nbr);
	return (count);
}

int	number_edge_case6(t_format *flg, int c, int w_nbr, int p_nbr)
{
	int	count;

	count = 0;
	if (c == 0 && p_nbr != -1 && w_nbr == -1)
	{
		count += width_padding(w_nbr);
		count += sign_case(flg, c);
	}
	else if (c == 0 && p_nbr != -1 && w_nbr != -1)
	{
		w_nbr += 1;
		count += width_padding(w_nbr);
		count += sign_case(flg, c);
	}
	else
	{
		count += width_padding(w_nbr);
		count += sign_case(flg, c);
		count += b_ft_putnbr(c);
	}
	return (count);
}

int	number_edge_case7(t_format *flg, int c, int w_nbr, int p_nbr)
{
	int	count;

	count = 0;
	if (c == 0 && w_nbr != -1 && p_nbr != -1)
	{
		w_nbr += 1;
		count += width_padding(w_nbr);
	}
	else if (c == 0 && w_nbr != -1)
	{
		count += b_ft_putnbr(c);
		count += width_padding(w_nbr);
	}
	else
	{
		count += sign_case(flg, c);
		count += b_ft_putnbr(c);
		count += width_padding(w_nbr);
	}
	return (count);
}
