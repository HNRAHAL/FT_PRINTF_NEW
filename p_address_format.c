/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_address_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:59:27 by hrahal            #+#    #+#             */
/*   Updated: 2025/10/26 14:08:18 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	p_number_case(va_list *list, t_format *flg, int w_nbr, int p_nbr)
{
	void	*ptr;
	char	*str;
	int		len;
	int		count;

	count = 0;
	ptr = va_arg(*list, void *);
	str = b_return_address_and_convert_to_hex(ptr);
	len = b_ft_strlen(str);
	if (w_nbr > len && p_nbr > len)
	{
		if (w_nbr <= p_nbr)
			count += p_number_case_two(str,	ptr ,p_nbr, len);
		else
			count += p_number_case_three(flg, ptr, w_nbr, p_nbr);
	}
	else if (w_nbr > len && w_nbr != -1)
		count += p_number_case_one(flg, ptr, w_nbr, len);
	else if (p_nbr > len && p_nbr != -1)
		count += p_number_case_two(str, ptr ,p_nbr, len);
	else
		count += p_else_case2(str, len , ptr);
	free(str);
	return (count);
}

int	p_number_case_one(t_format *flg, void *ptr, int w_nbr, int len)
{
	char *str;
	int	count;
	if(ptr == 0)
		w_nbr -= len + 3;
	else 
		w_nbr -= len + 2;
		
	str = b_return_address_and_convert_to_hex(ptr);
	count = 0;

	if (flg->minus_flag)
	{
		if(ptr == 0)
			count += b_ft_putstr("0x0");
		else
			count += b_ft_putstr("0x");
		while (len-- > 0)
			count += write(1, &str[len], 1);
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
	}
	else
	{
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
		if(ptr == 0)
			count += b_ft_putstr("0x0");
		else
			count += b_ft_putstr("0x");
		while (len-- > 0)
			count += write(1, &str[len], 1);
	}
	free(str);
	return (count);
}


int	p_number_case_two(char *str, void *ptr ,int p_nbr, int len)
{
	int	count;
	
	count = 0;
	if(ptr == 0)
	{
		count += b_ft_putstr("0x0");
		p_nbr -= len + 1;
	}
	else
	{
		count += b_ft_putstr("0x");
		p_nbr -= len;
	}
	while (p_nbr-- > 0)
		count += b_ft_putchar('0');
	while (len-- > 0)
		count += write(1, &str[len], 1);
	return (count);
}

int	p_number_case_three(t_format *flg, void *ptr, int w_nbr, int p_nbr)
{
	char *str;
	int	count;
	int	len;

	str = b_return_address_and_convert_to_hex(ptr);
	len = b_ft_strlen(str);
	count = 0;
	w_nbr -= p_nbr + 2;
	p_nbr -= len;
	if (flg->minus_flag)
	{

		count += b_ft_putstr("0x");
		while (p_nbr-- > 0)
			count += b_ft_putchar('0');
		while (len-- > 0)
			count += write(1, &str[len], 1);
		while (w_nbr-- > 0)
			count += b_ft_putchar(' ');
	}
	else
		count += p_else_case(str,w_nbr, p_nbr);
	free(str);
	return (count);
}

