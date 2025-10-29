/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_num_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:10:49 by hrahal            #+#    #+#             */
/*   Updated: 2025/10/29 16:10:50 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	u_edge_case1(int c, int w_nbr, int p_nbr)
{
	int	count;

	count = 0;
	if (c == 0 && w_nbr != -1 && p_nbr != -1 && p_nbr > 0)
	{
		w_nbr = -1;
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
		count += b_ft_putnbr_unsigned(c);
	}
	else if (c == 0 && w_nbr != -1 && p_nbr != -1 && p_nbr == 0)
	{
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
	}
	else if (c == 0 && p_nbr == 0)
		;
	else
		count += b_ft_putnbr_unsigned(c);
	return (count);
}

int	u_edge_case2(int c, int w_nbr, int p_nbr)
{
	int	count;

	count = 0;
	if (c == 0 && p_nbr == 0 && w_nbr != -1)
	{
		w_nbr += 1;
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
	}
	else if (c == 0 && p_nbr != -1 && w_nbr == -1)
	{
		w_nbr += 1;
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
	}
	else
	{
		count += b_ft_putnbr_unsigned(c);
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
	}
	return (count);
}

int	u_edge_case3(int c, int w_nbr, int p_nbr)
{
	int	count;

	count = 0;
	if (c == 0 && p_nbr > 0)
	{
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
		count += b_ft_putnbr_unsigned(c);
	}
	else if (c == 0 && p_nbr == 0)
	{
		w_nbr += 1;
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
	}
	else
	{
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
		count += b_ft_putnbr_unsigned(c);
	}
	return (count);
}

int	u_edge_case4(int c, int w_nbr, int p_nbr)
{
	int	count;

	count = 0;
	if (c == 0 && p_nbr != -1 && p_nbr > 0 && w_nbr != -1)
	{
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
		count += b_ft_putnbr_unsigned(c);
	}
	else if (c == 0 && p_nbr == 0)
	{
		w_nbr += 1;
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
	}
	else
	{
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
		count += b_ft_putnbr_unsigned(c);
	}
	return (count);
}
