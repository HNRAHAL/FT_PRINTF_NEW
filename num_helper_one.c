/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_helper_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:57:08 by hrahal            #+#    #+#             */
/*   Updated: 2025/10/29 12:44:44 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	number_combined_flags(t_format *flg, int w_nbr, int p_nbr, int c)
{
	int	count;

	count = 0;
	if(flg->plus_flag && flg->minus_flag && p_nbr != -1)
	{
		if(c == 0 && w_nbr != -1 && p_nbr == 0)
		{
			w_nbr += 1;
			count += sign_case(flg, c);
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
		}
		else
		{
			if(c == 0)
			{
				count += sign_case(flg, c);
				while (w_nbr-- > 0)
					count += b_ft_putchar(' ');
			}
			else
			{
				count += sign_case(flg, c);
				count += b_ft_putnbr(c);
				while (w_nbr-- > 0)
					count += b_ft_putchar(' ');
			}
		}
	}
	else if(flg->space_flag && flg->minus_flag && p_nbr != -1)
	{
		if(c == 0 && w_nbr != -1 && p_nbr == 0)
		{
			w_nbr += 1;
			count += sign_case(flg, c);
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
		}
		else 
		{	
			if(c == 0)
			{
				count += sign_case(flg, c);
				while (w_nbr-- > 0)
					count += b_ft_putchar(' ');
			}
			else
			{
				count += sign_case(flg, c);
				count += b_ft_putnbr(c);
				while (w_nbr-- > 0)
					count += b_ft_putchar(' ');
			}
		}
	}
	else if(flg->space_flag && flg->zero_flag && p_nbr != -1)
	{
		if(c == 0 && w_nbr != -1 && p_nbr == 0)
		{
			w_nbr += 1;
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
			count += sign_case(flg, c);
		}
		else 
		{	
			if(c == 0)
			{
				while (w_nbr-- > 0)
					count += b_ft_putchar(' ');
				count += sign_case(flg, c);
			}
			else
			{
				while (w_nbr-- > 0)
					count += b_ft_putchar(' ');
				count += sign_case(flg, c);
				count += b_ft_putnbr(c);
			}
			
		}
	}
	else if(flg->plus_flag && flg->zero_flag && p_nbr != -1)
	{
		if(c == 0 && w_nbr != -1 && p_nbr == 0)
		{
			w_nbr += 1;
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
			count += sign_case(flg, c);
		}
		else
		{
			if(c == 0)
			{
				while (w_nbr-- > 0)
					count += b_ft_putchar(' ');
				count += sign_case(flg, c);
			}
			else
			{
				while (w_nbr-- > 0)
					count += b_ft_putchar(' ');
				count += sign_case(flg, c);
				count += b_ft_putnbr(c);
			}

		}
	}
	else if ((flg->plus_flag && flg->minus_flag) || (flg->space_flag
			&& flg->minus_flag))
	{
		count += sign_case(flg, c);
		count += b_ft_putnbr(c);
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
	}
	else if ((flg->plus_flag && flg->zero_flag) || (flg->space_flag
			&& flg->zero_flag ))
	{
		count += sign_case(flg, c);
		while (w_nbr-- > 0)
			count += b_ft_putchar('0');
		count += b_ft_putnbr(c);
	}
	return (count);
}

int	number_individual_flags(t_format *flg, int w_nbr, int p_nbr,int c)
{
	int	count;

	count = 0;
	if (flg->plus_flag || flg->space_flag)
	{
		if(c == 0 && p_nbr != -1 && w_nbr == -1)
		{
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
			count += sign_case(flg, c);
		}
		else if(c == 0 && p_nbr != -1 && w_nbr != -1)
		{
			w_nbr += 1;
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
			count += sign_case(flg, c);
		}
		else
		{
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
			count += sign_case(flg, c);
			count += b_ft_putnbr(c);
		}
	}
	else if (flg->minus_flag)
	{
		if(c == 0 && w_nbr != -1 && p_nbr != -1)
		{
			w_nbr += 1;
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
		}
		else if(c == 0 && w_nbr != -1)
		{
			count += b_ft_putnbr(c);
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
		}
		else
		{
			count += sign_case(flg, c);
			count += b_ft_putnbr(c);
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
		}
	}
	else if (flg->zero_flag)
	{
		count += sign_case(flg, c);
		while (w_nbr-- > 0)
			count += b_ft_putchar('0');
		count += b_ft_putnbr(c);
	}
	return (count);
}
