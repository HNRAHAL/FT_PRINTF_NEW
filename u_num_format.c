/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_num_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 12:04:59 by hrahal            #+#    #+#             */
/*   Updated: 2025/10/29 12:45:07 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	u_number_case(va_list *list, t_format *flg, int w_nbr, int p_nbr)
{
	int				len;
	int				count;
	unsigned int	c;

	count = 0;
	c = va_arg(*list, unsigned int);
	len = b_unsigned_num_len(c);
	if (w_nbr > len && p_nbr > len)
	{
		if (w_nbr <= p_nbr)
			count += u_number_case_two(c, p_nbr, len);
		else
			count += u_number_case_three(flg, c, w_nbr, p_nbr);
	}
	else if (w_nbr > len && w_nbr != -1)
		count += u_number_case_one(flg, c, w_nbr, p_nbr);
	else if (p_nbr > len && p_nbr != -1)
		count += u_number_case_two(c, p_nbr, len);
	else
	{   
		if(c == 0 && w_nbr != -1 && p_nbr != -1 && p_nbr > 0)
		{
			w_nbr = -1;
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
			count += b_ft_putnbr_unsigned(c);
			
		}
		else if(c == 0 && w_nbr != -1 && p_nbr != -1 && p_nbr == 0)
		{
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
		}
 		else if(c == 0 && p_nbr == 0);
		else
			count += b_ft_putnbr_unsigned(c);
	}
	return (count);
}

#include <stdio.h> 
int	u_number_case_one(t_format *flg, int c, int w_nbr, int p_nbr)
{
	int	count;
	int len;

	len = b_unsigned_num_len(c);
	count = 0;
	w_nbr -= len;
	if (flg->minus_flag)
	{
		if(c == 0 && p_nbr == 0 && w_nbr != -1)
		{
			w_nbr += 1;
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
		}
		
		else if(c == 0 && p_nbr != -1 && w_nbr == -1)
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
	}
	else if (flg->zero_flag && p_nbr != -1)
	{
		if (c == 0 && p_nbr > 0)
		{
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
			count += b_ft_putnbr_unsigned(c);
		}
		else if(c == 0 && p_nbr == 0)
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
	}
	else if (flg->zero_flag)
	{
		while (w_nbr-- > 0)
			count += b_ft_putchar('0');
		count += b_ft_putnbr_unsigned(c);
	}
	else
	{
		if(c == 0 && p_nbr != -1 && p_nbr > 0 && w_nbr != -1)
		{
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
			count += b_ft_putnbr_unsigned(c);
		}
		else if(c == 0 && p_nbr ==0 )
		{
			w_nbr += 1;
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
		}
		else if(c == 0)
		{
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
			count += b_ft_putnbr_unsigned(c);
		}
		else
		{
			while (w_nbr-- > 0)
				count += b_ft_putchar(' ');
			count += b_ft_putnbr_unsigned(c);
		}
	}
	return (count);
}

int	u_number_case_two(int c, int p_nbr, int len)
{
	int	count;

	count = 0;
	p_nbr -= len;
	while (p_nbr-- > 0)
		count += b_ft_putchar('0');
	count += b_ft_putnbr_unsigned(c);
	return (count);
}

int	u_number_case_three(t_format *flg, int c, int w_nbr, int p_nbr)
{
	int	count;
	int	len;

	count = 0;
	len = b_unsigned_num_len(c);
	w_nbr -= p_nbr;
	p_nbr -= len;
	if (flg->minus_flag)
	{
		while (p_nbr-- > 0)
			count += b_ft_putchar('0');
		count += b_ft_putnbr_unsigned(c);
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
	}
	else
	{
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
		while (p_nbr-- > 0)
			count += b_ft_putchar('0');
		count += b_ft_putnbr_unsigned(c);
	}
	return (count);
}
