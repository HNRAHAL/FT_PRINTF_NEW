/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_hex_lower_helper_three.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:53:27 by hrahal            #+#    #+#             */
/*   Updated: 2025/10/29 16:53:36 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	x_lower_edge_case1(t_format *flg, int num, int w_nbr, int p_nbr)
{
	char	*str;
	int		count;

	count = 0;
	str = b_return_hexvalue_lower(num);
	if (w_nbr <= p_nbr)
		count += x_lower_number_case_two(flg, str, num, p_nbr);
	else
		count += x_lower_number_case_three(flg, num, w_nbr, p_nbr);
	free(str);
	return (count);
}

int	x_lower_edge_case2(t_format *flg, int num, int w_nbr, int p_nbr)
{
	int		len;
	int		count;
	char	*str;

	str = b_return_hexvalue_lower(num);
	len = b_ft_strlen(str);
	count = 0;
	w_nbr -= len + 2;
	if ((flg->minus_flag && flg->hash_flag) || (flg->zero_flag
			&& flg->hash_flag))
		count += x_lower_number_combined_flags(flg, num, w_nbr, p_nbr);
	else if (flg->hash_flag)
		count += x_lower_edge_case3(str, w_nbr, len);
	else if (flg->zero_flag && p_nbr != -1)
		count += x_lower_edge_case4(str, w_nbr, len);
	else if (flg->zero_flag)
		count += x_lower_edge_case5(str, w_nbr, len);
	else
		count += x_lower_number_else_case(flg, str, w_nbr, len);
	free(str);
	return (count);
}

int	x_lower_edge_case3(char *str, int w_nbr, int len)
{
	int	count;

	count = 0;
	count += width_padding(w_nbr);
	count += b_ft_putstr("0x");
	count += print_string(str, len);
	return (count);
}

int	x_lower_edge_case4(char *str, int w_nbr, int len)
{
	int	count;

	count = 0;
	w_nbr += 2;
	count += width_padding(w_nbr);
	count += print_string(str, len);
	return (count);
}

int	x_lower_edge_case5(char *str, int w_nbr, int len)
{
	int	count;

	count = 0;
	w_nbr += 2;
	while (w_nbr-- > 0)
		count += b_ft_putchar('0');
	count += print_string(str, len);
	return (count);
}
