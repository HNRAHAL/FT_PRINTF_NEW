/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_and_s_helper_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:49:59 by hrahal            #+#    #+#             */
/*   Updated: 2025/10/29 13:50:46 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	string_edge_case1(t_format *flg, char *temp, int w_nbr, int p_nbr)
{
	int	count;
	int	i;

	count = 0;
	w_nbr -= p_nbr;
	i = 0;
	if (flg->minus_flag)
	{
		while (p_nbr-- > 0)
			count += write(1, &temp[i++], 1);
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
	}
	else
	{
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
		while (p_nbr-- > 0)
			count += write(1, &temp[i++], 1);
	}
	return (count);
}

int	string_edge_case2(t_format *flg, char *str, int w_nbr, int len)
{
	int	count;

	count = 0;
	w_nbr -= len;
	if (flg->minus_flag)
	{
		count += b_ft_putstr(str);
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
	}
	else
	{
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
		count += b_ft_putstr(str);
	}
	return (count);
}

int	string_null_edge_case(t_format *flg, char *str, int w_nbr, int p_nbr)
{
	char	*temp;
	int		count;
	int		len;
	int		i;

	i = 0;
	count = 0;
	len = 6;
	temp = "(null)";
	if ((p_nbr >= 0 && p_nbr <= len && w_nbr != -1))
		count += string_edge_case1(flg, temp, w_nbr, p_nbr);
	else if (p_nbr <= len && p_nbr != -1)
	{
		while (p_nbr-- > 0)
			count += write(1, &temp[i++], 1);
	}
	else if (w_nbr > len && w_nbr != -1)
		count += string_edge_case2(flg, str, w_nbr, len);
	else
		count += b_ft_putstr(str);
	return (count);
}
